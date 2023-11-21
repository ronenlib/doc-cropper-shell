# Doc Cropper Shell

## Introduction

Doc Cropper Shell is a shell script designed for automatically cropping a document from an image.

### To Do
- Fine tune doc adjustment
- Regression tests

## Prerequisites

- Ubuntu 
- OpenCV

```bash
apt-get install libopencv-dev
```

Otherwise install OpenCV and update `INCLUDE_PATH` (see `Makefile`) to point to OpenCV headers and libraries. 

## Installation

Clone

```bash
git clone https://github.com/ronenlib/doc-cropper-shell.git
cd doc-cropper-shell
```

Compile

```bash
make
```

## Usage

```bash
doc-cropper input_img.jpg
```