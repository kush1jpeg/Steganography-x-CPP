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
g++ file.cpp bin.cpp working.cpp msg.cpp decrypt.cpp xor.cpp -o output.exe
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

# Future Plans + Learning 🌟
I’m thinking of first encrypting the message using an algorithm. What I have in mind is generating a passkey by hashing some of the metadata from the image, then encrypting the message and storing it inside the image as binary data. This way, it would be almost unbreakable (well, not literally, but very secure 😎). I’m definitely going to do this since I've already used the Caesar Cipher algorithm in my File Encryptor and Decryptor project, so it should be easy for me. Ahh, I’ve yapped too much 😅.

Also, I still need to figure out how to work with pipes in C++, because I honestly know jack-shit about them and had to remove the whole function that used pipes and rewrite it by uk creating files like a p$y🐱.

Edit: I’ve done some basic encryption on the message being inputted before converting it into binary using XOR. Now, I really want to implement SHA-256. However, making it from scratch would complicate the project unnecessarily, and I don’t want to use any fucking crappy library just to get the job done;