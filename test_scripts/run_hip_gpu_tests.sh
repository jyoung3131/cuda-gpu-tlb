#!/bin/bash
# This script file allows the user to repeatably run the test for a newer AMD GPU
TOPDIR=$HOME/git_repos/cuda-gpu-tlb-hip/
TESTDIR=release
cd $TOPDIR/$TESTDIR

#Put your list of tests to run here
#L1 tests - note these may be too small to see any meaningful results on MI100
#./tlb_benchmark 20 80 1024 256
#./tlb_benchmark 20 80 4096 8192
#./tlb_benchmark 128 512 16384 32768
#./tlb_benchmark 1024 4096 16384 32768 20
#./tlb_benchmark 1024 4096 16384 32768 20
./tlb_benchmark 8192 16000 1024 2048 1

#Return to last directory - wherever this script was called from
cd -
