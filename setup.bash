git submodule update --init --recursive

# oneTBB
cd oneTBB
make
TBB_LIB=$(find ./build -name "libtbb.so" -exec realpath {} \;)
TBB_INCLUDE=$(realpath ./include)
cd ..

# np-schedulability-analysis
cd np-schedulability-analysis
git apply ../np-schedulability-analysis.diff
cd ..

# DAG-scheduling
mkdir build && cd build
cmake .. -DTBB_INCLUDE_DIR=$TBB_INCLUDE -DTBB_LIBRARY=$TBB_LIB
make
