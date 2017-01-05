# Predict Proteins' Secondary Structure Using Artificial Neural Network

## Install on Ubuntu (or other linux)
1. make
2. sudo make install
Since I'm new to makefile, you could modify it if the _make_ is not working well.

## How to use PSSP-proto
1. ./PSSP-proto
2. PSSP-proto
## How to use PSSPcc
1. ./PSSPcc -h
2. PSSPcc -h

## About the design
Inspired by the megacc and megaproto, I designed PSSPcc and PSSP-proto. GUI will help user to assign parameters for core computational program, and visualize the output. In the PSSP-proto, user can choose parameters for different analysis tasks (training, prediction or test). Then user run the PSSPcc to get the result.

The design like these will accelerate batch running on different settings. User could generate their own setting files (.pssp) and send to the PSSPcc. If using a GUI version, this batch running is horrible (we should set settings and click on run by hand).

## For release
zip -f PSSPANN_V1.zip
