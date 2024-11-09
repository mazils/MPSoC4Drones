#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
extern "C" void image_processing(char*, int, int);
extern "C" void apatb_image_processing_hw(volatile void * __xlx_apatb_param_in, volatile void * __xlx_apatb_param_out) {
  // Collect __xlx_in_out__tmp_vec
  vector<sc_bv<8> >__xlx_in_out__tmp_vec;
  for (int j = 0, e = 921600; j != e; ++j) {
    __xlx_in_out__tmp_vec.push_back(((char*)__xlx_apatb_param_in)[j]);
  }
  int __xlx_size_param_in = 921600;
  int __xlx_offset_param_in = 0;
  int __xlx_offset_byte_param_in = 0*1;
  for (int j = 0, e = 921600; j != e; ++j) {
    __xlx_in_out__tmp_vec.push_back(((char*)__xlx_apatb_param_out)[j]);
  }
  int __xlx_size_param_out = 921600;
  int __xlx_offset_param_out = 921600;
  int __xlx_offset_byte_param_out = 921600*1;
  char* __xlx_in_out__input_buffer= new char[__xlx_in_out__tmp_vec.size()];
  for (int i = 0; i < __xlx_in_out__tmp_vec.size(); ++i) {
    __xlx_in_out__input_buffer[i] = __xlx_in_out__tmp_vec[i].range(7, 0).to_uint64();
  }
  // DUT call
  image_processing(__xlx_in_out__input_buffer, __xlx_offset_byte_param_in, __xlx_offset_byte_param_out);
// print __xlx_apatb_param_in
  sc_bv<8>*__xlx_in_output_buffer = new sc_bv<8>[__xlx_size_param_in];
  for (int i = 0; i < __xlx_size_param_in; ++i) {
    __xlx_in_output_buffer[i] = __xlx_in_out__input_buffer[i+__xlx_offset_param_in];
  }
  for (int i = 0; i < __xlx_size_param_in; ++i) {
    ((char*)__xlx_apatb_param_in)[i] = __xlx_in_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_out
  sc_bv<8>*__xlx_out_output_buffer = new sc_bv<8>[__xlx_size_param_out];
  for (int i = 0; i < __xlx_size_param_out; ++i) {
    __xlx_out_output_buffer[i] = __xlx_in_out__input_buffer[i+__xlx_offset_param_out];
  }
  for (int i = 0; i < __xlx_size_param_out; ++i) {
    ((char*)__xlx_apatb_param_out)[i] = __xlx_out_output_buffer[i].to_uint64();
  }
}
