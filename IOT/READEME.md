# IoT Object Detection System

This repository contains the IoT part of the larger project, focusing on object detection using machine learning. It utilizes the YOLO (You Only Look Once) framework for real-time object detection. This system is capable of processing images and video streams to detect objects, which can be particularly useful in scenarios like security, traffic monitoring, etc.

## Table of Contents

- [Installation](#installation)
- [File Descriptions](#file-descriptions)
- [Usage](#usage)
- [GUI Visualization](#gui-visualization)
- [Training Your Model](#training-your-model)
- [Detection](#detection)
- [Contributing](#contributing)
- [License](#license)

## Installation

Before you begin, ensure you have met the following requirements:
- You have installed Python 3.x
- You have a Windows/Linux/Mac machine.

To install the project, you need to clone the repository and install the dependencies:

```bash
git clone https://github.com/awexxxx/Group_54.git
cd Group_54/IOT/
pip install -r requirements.txt  # You need to create this file based on your project's external libraries.
```

## File Descriptions

- `GUI.py`: This script sets up a graphical user interface (GUI) for comparing images before and after detection.
- `detect_pic.py`: This script uses a pre-trained model to detect objects in images.
- `detect_video.py`: Similar to `detect_pic.py`, but this script is for video streams.
- `train.py`: This script is used for training a YOLO model with custom data.

## Usage

### GUI Visualization

To visualize the detection results, run the `GUI.py` script. It will display images before and after object detection.

```bash
python GUI.py
```

### Training Your Model

If you need to train the model with new data, use the `train.py` script. Make sure to configure your dataset path in the script.

```bash
python train.py
```

### Detection

For detecting objects in images or video streams, use the `detect_pic.py` and `detect_video.py` scripts, respectively.

```bash
python detect_pic.py
python detect_video.py
```
