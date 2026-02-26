# Melani 2015 (GP-FP-EDF) Schedulability Analysis

## Install

```bash
git clone https://github.com/atsushi421/DAG-scheduling.git
cd DAG-scheduling
git submodule update --init --recursive

# Build oneTBB
cd oneTBB
make
TBB_LIB=$(find ./build -name "libtbb.so" -exec realpath {} \;)
TBB_INCLUDE=$(realpath ./include)
cd ..

# Patch np-schedulability-analysis
cd np-schedulability-analysis
git apply ../np-schedulability-analysis.diff
cd ..

# Build
mkdir build && cd build
cmake .. -DTBB_INCLUDE_DIR=$TBB_INCLUDE -DTBB_LIBRARY=$TBB_LIB
make melani2015_only
```

## Usage

```bash
./melani2015_only <taskset_file> [n_proc]
```

- `<taskset_file>`: YAML or DOT format taskset file
- `[n_proc]`: Number of processors (default: 4)

### Example

```bash
./melani2015_only ../demo/taskset.yaml 4
```

Output:

```
Melani 2015 constrained (GP-FP-EDF): 1
```

`1` = schedulable, `0` = not schedulable.
