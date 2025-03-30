# Steganography-x-CPP

A cool terminal-based steganography tool inspired by the famous Cicada 3301, the mysterious internet puzzle that appeared in 2012 :Some images posted by Cicada contained hidden messages that could only be revealed through steganographic techniques; written in C++ this project hides messages inside images using the Least Significant Bit (LSB) technique though frucks up the image little bit:)

## 🚀 Features
- Encode a secret message into an image
- Decode the hidden message from an image 
- Supports all the img formats for easy manipulation

## 📌 Prerequisites
Before using the tool, ensure you have the following installed:

- **G++ Compiler (or any other)** (for compiling the C++ code)
- **ImageMagick** (for converting images to PPM format)

### 🎯 Install ImageMagick
Download and install ImageMagick from the official site:

[ImageMagick Download](https://imagemagick.org/script/download.php)

After installation, verify with:
```sh
magick --version
```

## 🛠️ Installation
Clone the repository and compile the C++ files:

```sh
git clone https://github.com/yourusername/Steganography-x-CPP.git
cd Steganography-x-CPP
g++ file.cpp bin.cpp converting.cpp working.cpp ppmToOther.cpp -o steg
```

## 🖥️ Usage

### Compile all the files using the compiler-
for gcc-
```sh
gcc bin.cpp convertIng.cpp file.cpp ppmToOther.cpp working.cpp -o output     
```
//for windows output.exe file will be formed and on linux simply output file will be formed

Run the output file:
```sh
./output.exe
```


## How It Works
1. The message is converted into a binary sequence.
2. The LSB of selected pixels is modified to store the message.
3. During decoding, LSB values are extracted to reconstruct the message.

## Contributing
Feel free to contribute by submitting issues or pull requests.   (I still have to add the decoding part)
