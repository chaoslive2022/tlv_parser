# Description
BER Tag Length Value parser

## Version
v0.1.0.0

## Status
Under elaboration and construction

## Characteristic
C implementation to target embedded platforms

# Usage

## Make
From root directory:
```
cmake -DUSE_GTEST=ON -S .\src\ -B .\build\
```

## Build
From root directory:
```
cmake --build .\build\
```

## Run
```
cd build && ctest
```

Or

```
cd build && .\tlv_parser
```

