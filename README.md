# CPU Info Utility for Yocto

This project provides a simple C program that displays basic CPU and memory information by reading from the `/proc` filesystem. It is packaged as a Yocto recipe to integrate easily into custom embedded Linux images built with Yocto Project.

## Features

- Displays CPU details from `/proc/cpuinfo`
- Displays memory details from `/proc/meminfo`
- Lightweight utility suitable for embedded environments
- Easily integrated into Yocto build via a custom recipe

## Yocto Recipe Overview

The recipe `cpuinfo.bb`:

- Clones the source from a git repository
- Compiles the program using the Yocto toolchain
- Installs the binary into the target image's `/usr/bin`
- Properly sets metadata including license (MIT)

## How to Build

1. Place the recipe in your custom layer under `recipes-core/cpuinfo/`.
2. Add `cpuinfo` to your image recipe (`my-core-image.bb`).
3. Run

   ```bash
   bitbake my-core-image
   ```

4. After a successful build, the `cpuinfo` executable will be available in your target root filesystem.

## Example Usage

Run the command on the target device:

```bash
cpuinfo
```

This will print CPU and memory information directly to the console.

*** 

## How the Yocto Recipe Fetches the Source Code

The Yocto recipe uses the `SRC_URI` variable to specify the location of the source code repository. For this project, the recipe fetches the source code directly from a Git repository hosted on GitHub.

Example `SRC_URI` in the recipe:

```
SRC_URI = "git://github.com/Shabari-K-S/yocto-test.git;protocol=https;branch=main"
```

- `git://github.com/Shabari-K-S/yocto-test.git` specifies the remote Git repository URL.
- `protocol=https` forces the recipe fetcher to use HTTPS protocol instead of the deprecated Git protocol.
- `branch=main` tells the fetcher to clone the `main` branch.

The commit or version to be used is controlled by the `SRCREV` variable:

```
SRCREV = "${AUTOREV}"
```

- `${AUTOREV}` automatically fetches the latest commit on the branch specified.
- Alternatively, a specific commit SHA1 hash can be provided for reproducible builds.

The source code is cloned into a working directory defined by:

```
S = "${WORKDIR}/git"
```

Once fetched, BitBake compiles the program from this local copy.

This setup allows seamless integration of upstream development in the Yocto build process, ensuring the latest or specified version of the code is included in your custom embedded image.
