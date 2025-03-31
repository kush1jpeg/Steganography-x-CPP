# Steganography-x-CPP
<table>
  <tr>
    <td>
      <img src="https://imgs.search.brave.com/0Pq9HWXaui3Pgz3lR2FNxb5xCNsHnQtFJNOz7BDma-I/rs:fit:500:0:0:0/g:ce/aHR0cHM6Ly93d3cu/Y2ljYWRhMzMwMW9m/ZmljaWFsLmNvbS9j/b250ZW50L2ltYWdl/cy9jaWNhZGEtMzMw/MS1tYWluLndlYnA" alt="Cicada 3301" width="300">
    </td>
    <td >

A cool terminal-based steganography tool inspired<br>
by the famous Cicada 3301, the mysterious internet<br>
puzzle that appeared in 2012 :Some images posted by<br>
Cicada contained hidden messages that could only be<br>
revealed through steganographic techniques; written<br>
in C++ this project hides messages inside images using<br>
the selective Least Significant Bit (LSB) technique<br>
sorta like the one used in Cicada 3301:)
</td>
</tr>
</table>

```md
  _____ _               _       ____ 
 / ____(_)             | |     |___ \
| |     _  ___ __ _  __| | __ _  __) |
| |    | |/ __/ _` |/ _` |/ _` ||__ <  
| |____| | (_| (_| | (_| | (_| |___) |                    
\_____|_|\___\__,_|\__,_|\__,_|___ a ripOff by kush-
```

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

After installation as per your OS, verify it with:
```sh
magick --version
```

## 🛠️ Installation
Clone the repository and compile the C++ files:

```sh
git clone https://github.com/kush1jpeg/Steganography-x-CPP.git
cd Steganography-x-CPP
```

## 🖥️ Usage

### Compile all the files using the compiler-
for gcc-
```sh
g++ file.cpp bin.cpp working.cpp msg.cpp decrypt.cpp -o output.exe
```
//for windows output.exe file will be formed and on linux simply output file will be formed

Run the output file:
```sh
./output.exe
```

## How It Works
1. The message is converted into a binary sequence.
2. My approach is a variation of LSB steganography :

    -Find the smallest value among R, G, and B in a pixel.

    -Extract its "ones place" digit (e.g., if Red = 23, you take 3).

    -Replace this ones place digit with a binary from your hidden message.

3. During decoding, the ones place of the smallest value among rgb of a pixel is extracted to reconstruct the message.

## Contributing
Feel free to contribute by submitting issues or pull requests or some improvements  

## Future Plans + Learning 
I can still first encrypt the message using some algo -> wat i am thinking is to generate a passkey by hashing some of the meta data from the image and then encrypt the message and then store it inside the image in the form of binaries so it would almost be unbreakable(not literally but very secure as a matter of fact). I will definitely do it cuz you know as i have already used Caesar-Cipher algo before for my file Encryptor and Decryptor project so it will be easy for me ahmm i yapped too much. also i still have to figure out how to work with pipes in cpp cuz i know jackshit about them and eventually had to remove the whole func which used pipe and write it by creating files like a pu$y;

