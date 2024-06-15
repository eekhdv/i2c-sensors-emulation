# Part of the course work (3rd course)

## High-Performance and Scalable Linux Service for Reading I2C Sensor Data (ORAN 5G Fronthaul Specification)

This repository contains the implementation of a Linux service designed for reading data from I2C sensors according to the O-RAN 5G fronthaul (split 7) specification. This project was developed as part of my coursework and demonstrates the implementation of the I2C sensor reading service for future implementation in the 5G network infrastructure.

<details>
  <summary>Presentation teaser</summary>

![https://ibb.co/xYtZSt4](https://i.ibb.co/7QdhJd9/2024-06-15-T15-16-46-566869754-03-00.png)

![https://ibb.co/3WYLVY1](https://i.ibb.co/K7z3Bz6/2024-06-15-T15-16-57-663124344-03-00.png)

![https://ibb.co/60SR7NS](https://i.ibb.co/d4v0w7v/2024-06-15-T15-17-05-797316610-03-00.png)

![https://ibb.co/7vfyd4N](https://i.ibb.co/8MC8Lc4/2024-06-15-T15-17-11-980478474-03-00.png)

</details>
  
### Requirements

- Linux-based operating system
- I2C kernel modules enabled
- Sensors connected to the MC via i2c bus (or SM bus)
- `i2c-tools`, `cmake`

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/your-repository.git
   cd i2c-dev-emulation
   ```
2. Build the project:
   ```sh
   mkdir build & cd build
   cmake ..
   make
   ```
