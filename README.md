# Description
BER TV parser

## Version
v0.1.0.0

## Status
Under elaboration and construction...

## Characteristics
- C implementation to target embedded platforms
- Google test unit supported

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

