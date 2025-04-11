# What is ucd?

u(ber)cd is a utility that allows you to stack and unstack directories meanwhile navigating using your favorite shells and terminals. <br>
The difference with what already exists is that this works out 
of the box on ANY terminal, and that it supports multiple platforms. The 
behaviour is very simple yet so poweful. <br>
This utility has no dependency.

## Build and install

You can either download the prebuilt binaries, or build from the source, the following describes the process of building and installing.

### Windows

* Clone the repository.
* Execute `build.bat`
* Make sure to have both `ucd.bat` and `_internal_ucd` in a directories that's in the **%PATH%** environment variable.

### Linux

The 2 first steps are basically the same, but execute `build.sh` instead of 
`build.bat`.
Since Linux shell scripts require creation of another process, we cannot execute
`ucd.sh` to actually change the working directory.
To overcome this, we add `ucd` logic to `~/.bashrc`. To do so execute `install.sh`.
Finally ensure to have the folder containing `_internal_ucd` in %$PATH% envrionment variable.

## Examples

