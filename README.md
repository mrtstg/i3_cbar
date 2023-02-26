# i3_cbar

Custom status bar for i3 shell.

## Warning

This project was written for studying, it may not work properly on your PC, but you can also use it as simple example for i3 bar proto.

## What it does?

Bar shows:

- Current date and time
- Brightness level
- Volume level
- Battery level

Bar updates every 250 ms. (about 4 times in second)

## How to build

1. Pull JSON library

```
make libs
```

2. Build!

```
make build
```

## Programs which bar uses for getting info

- amixer
- brightnessctl
