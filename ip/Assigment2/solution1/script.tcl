############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Assigment2
set_top image_processing
add_files main.cpp
add_files -tb main_tb.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xczu3eg-sbva484-1-i}
create_clock -period 10 -name default
config_export -format ip_catalog -output /home/mazils/Desktop/turbo-train-EMB2/ip/image_processing.zip -rtl vhdl
source "./Assigment2/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl vhdl -format ip_catalog -output /home/mazils/Desktop/mp4d/MPSoC4Drones/ip/image_processing.zip
