

<p align="center">
    <img src= "https://github.com/user-attachments/assets/61fdd2ce-aab0-454c-a5f5-c897afbc5a62"
        height="300">
</p>
<p align="center">
    <a href="mailto:wildric.auric@gmail.com" alt="Email">
        <img src="https://img.shields.io/badge/Gmail-D14836?logo=gmail&logoColor=white" /></a>
    <a href="https://github.com/Wildric-Auric/ucd/edit/main/README.md#linux" alt="Linux">
        <img src="https://img.shields.io/badge/Linux-FCC624?logo=linux&logoColor=black" /></a>
    <a href="https://github.com/Wildric-Auric/ucd/edit/main/README.md#windows" alt="Windows">
        <img src="https://custom-icon-badges.demolab.com/badge/Windows-0078D6?logo=windows11&logoColor=white"/></a>
    <a href="http://github.com/Wildric-Auric/ucd/stargazers" alt="stars">
        <img src="https://img.shields.io/github/stars/Wildric-Auric/ucd?style=flat"/></a>
    <a href="https://github.com/Wildric-Auric/ucd/forks" alt="forks">
        <img src="https://img.shields.io/github/forks/Wildric-Auric/ucd?style=flat"/></a>
    <a href= "https://buymeacoffee.com/wildric" alt="Windows">
        <img src= "https://img.shields.io/badge/Buy%20Me%20a%20Coffee-ffdd00?&logo=buy-me-a-coffee&logoColor=black" /></a>
</p>

------

u(ber)cd is a utility that allows you to stack and unstack directories meanwhile navigating using your favorite shells and terminals. <br>
The difference with what already exists is that this works out 
of the box on ANY terminal, and that it supports multiple platforms. The 
behaviour is very simple yet so poweful. <br>
This utility has no dependency.

## Build and install

You need to build and install.

### Windows

* Clone the repository.
* Execute `build.bat`
* Make sure to have both `ucd.bat` and `_internal_ucd` in a directory that's in the **%PATH%** environment variable.

### Linux

* Clone the repository.
* Execute `build.sh`
* Execute `install.sh ~/your/directory/of/install`

Once ucd is installed, type `ucd --help`.
## Note on Linux implementation

Since Linux shell scripts require creation of another process, we cannot execute
`ucd.sh` to actually change the working directory.
To overcome this, we add `ucd` logic to `~/.bashrc`. To do so we execute `install.sh`.

## Examples

<p align="center">
  <img src="https://github.com/user-attachments/assets/7f2ba6a7-9ac9-484e-97f0-3c0dd4170889" alt="Description" width="800" />
</p>

## Features

If you have any suggetion for a feature or an imporovement, don't hesitate to report in issues section.

