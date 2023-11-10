<p align="center">
A macro software that helps you automate tasks. <br>
Main feature, simulate user's inputs such as keyboard input, mouse movement, write sentence.
</p>


# Syntax

## WAIT
> Halt the program for a certain amount of milliseconds.

```yaml
    WAIT: millis
```
Example: `WAIT: 5000` stops the program for 5 seconds.

## PRESS
> Simulate a keyboard press (press and release). <br>
> Current version only supports non-capitalized alphabet characters and numbers from 0 to 9.

```yaml
    PRESS: key
```
Example: `PRESS: A` results in 'a' pressed

**Attention**:
* Uppercase `A` will be treated as lowercase `a`. 
* Unsupported keys will return error.

# MOVE
> **Teleports** your cursor to provided position of _X_ and _Y_.

```yaml
    MOVE: x,y
```
Example: `MOVE: 100, 200` will **teleport** your cursor to position 100, 200 on the screen.

**Attention**:
* If value exceeds screen's resolution. Mouse will get moved to your screen's resolution (bottom-right corner).

# WRITE
> Type provided string to currently focus window.

```yaml
    WRITE: texts
```
Example: `WRITE: Hello, World!` simulates user typing "**_Hello, World!_**" to currently focused window.

**Attention**:
* `\n` or `\t` will be treated as escape sequence character. Currently, there's no way to print these out.


# Installation

<h2 accesskey="debian">
    <img 
        alt="debian-logo" 
        src="https://cdn.icon-icons.com/icons2/2415/PNG/32/debian_original_logo_icon_146566.png" 
        height="24px"
    />
    Debian / Ubuntu
</h2>
<p align="center ">
    <b>
        THIS PROGRAM REQUIRES SUDO PRIVILEGE
    </b>
</p>

> Due to lack of support, Debian and other depravities must do more work. <br>

1. Download [**ydotool-release-ubuntu-latest**](https://github.com/ReimuNotMoe/ydotool/releases/latest):
2. Download [**ydotoold-release-ubuntu-latest**](https://github.com/ReimuNotMoe/ydotool/releases/latest)
3. Turn them into executable file: `chmod +x ydotool*`
4. Copy files into its location:
    * `sudo cp ydotool-release-ubuntu-latest /usr/bin/ydotool`
    * `sudo cp ydotoold-release-ubuntu-latest /usr/bin/ydotoold`
5. Run **ydotool** daemon as root: `sudo ydotoold`
    > Notice here, that the daemon requires to be running before executing script. <br>
      Keep the terminal open or make it persistent by using [systemd/Services](https://wiki.debian.org/systemd/Services)
6. Download latest version of the [Macro Scripting Lang](https://github.com/knighthat/macro-scripting-lang/releases)
7. Run the script as root `sudo ./macro-scripting-lang <file>`

<h2>
    <img 
        alt="archlinux-logo"
        src="https://cdn.icon-icons.com/icons2/1381/PNG/32/distributorlogoarchlinux_94330.png"
        height="24px"
    />
    Arch Linux
</h2>

1. Install `ydotool` from package manager: `sudo pacman -S ydotool`
2. Run **ydotool** daemon: `ydotoold`
    > Unlike Debian, you don't need to have ROOT privilege to run daemon.<br>
    > Though, daemon must be running to execute scripts. Make it permanent with [.service](https://wiki.archlinux.org/title/systemd) file
3. Download latest version of the [Macro Scripting Lang](https://github.com/knighthat/macro-scripting-lang/releases)
4. Run script: `./macro-scripting-lang <file>`
