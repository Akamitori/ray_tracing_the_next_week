# Ray Tracing : The next week

A C++ implementation of the book **[Ray Tracing : The Next Week ](https://raytracing.github.io/books/RayTracingTheNextWeek.html)** by Peter Shirley.



## Overview

This project walks through the basics of ray tracing, following the structure from the book. It covers core concepts
like rays, materials, lighting, and advanced features like anti-aliasing and defocus blur.

Key features:

- **Basic Ray Tracing**: Render simple scenes with spheres and basic lighting.
- **Materials**: Add realism with diffuse, reflective, and transparent materials.
- **Anti-Aliasing**: Smooth edges with multi-sampling.
- **Defocus Blur**: Simulate camera effects with depth of field.
- **TBA**

## Getting Started

### Prerequisites

- **C++11** or later
- A C++ compiler (`g++`, `clang`, etc.)
- `Make` or `CMake` for building

### Building

1. **Clone the repo**:
   ```shell
   # clone the repo
   git clone https://github.com/Akamitori/ray_tracing_the_next_week.git
   
   # change the directory to the repo directory
   cd ray_tracing_the_next_week

2. **Build the project**:
   ```shell
   # Using CMake
   mkdir build && cd build
   cmake ..
   make
   ```

3. **Build Configurations**:
    - By default, CMake builds in **Debug mode**, which includes extra debugging symbols and performs less aggressive
      optimizations.

    - To build in **Release mode** for better performance:
      ```shell
      cmake -DCMAKE_BUILD_TYPE=Release ..
      make
      ```

    - To build in **Debug mode** (if needed):
      ```shell
      cmake -DCMAKE_BUILD_TYPE=Debug ..
      make
      ```

### Running

Once built, run the ray tracer:

```bash
./raytracer
```

The output image will be generated as a `.ppm` file with the name `output.ppm`.

## Viewing the output

The output can be viewed with any photo processing program or by using [IrfanView](https://www.irfanview.com/)
or by using this online [PPM viewer](https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html)



## License

This project is licensed under the MIT License.
