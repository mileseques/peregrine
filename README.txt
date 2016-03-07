Peregrine
Cross-platform emulator for legacy Windows applications, built on QEMU and ReactOS.

Alas, I talk about this as though I already had the thing finished, when in fact it is scarcely started. Ah well. I've been experimenting and doing research for weeks, and I've made enough design decisions that I can get started writing code that (theoretically) will go into an end product. So now it makes sense to set up a GitHub repository.

Peregrine is going to be optimized for games, and is intended to support running applications built for Windows 9X and 2000-XP (that is, Windows 95, Windows 98, Windows ME, Windows 2000, and Windows XP). It is targeted to be run on the following platforms:
*Android
*iOS (there may be some complications to this end, see below)
*Linux (likely Debian-based distros primarily)
*OS X
*Windows

Additionally, an eventual goal of the project is to wrap Peregrine as a Libretro core (see http://www.libretro.com/), which would extend support to the considerable range of platforms supported by RetroArch (including a variety of modern video game platforms)

While support for iOS itself is hardly ambitious compared to the other project goals, the iTunes App Store has been known to reject emulators in general. I'm not sure Apple has released an official statement regarding this behavior, but it's likely connected to objections over copyright infringement. There is also a prohibition on apps which can launch executable code in general. Even if rejected by the app store, though, Peregrine can still be installed on jailbroken iOS devices.

The project will be built in C and C++ using Eclipse as the primary IDE and gcc as the compiler.

The main components will include:
*A feature-light fork of QEMU, which will emulate the processor(s) on non-x86 host machines and provide virtualized memory for the runtime environment. QEMU is built in C. More about QEMU at https://en.wikipedia.org/wiki/QEMU
*A fork of the ReactOS kernel, which will do kernely stuff like managing memory and scheduling threads in the runtime environment. For performance, the kernel will run natively alongside QEMU (rather than being emulated *by* QEMU). This will likely require some serious modification to allow it to run in the user space. The ReactOS kernel is built in C. More about ReactOS at https://en.wikipedia.org/wiki/ReactOS
*A fork of Wine, though we will probably only include front-end components. This will expose Windows API functions and services to guest applications. Wine is built in C. More about Wine at https://en.wikipedia.org/wiki/Wine_(software)
*Custom Wine back-end, which will convert Windows API calls 
*DOSBox. Probably the whole thing, it's incredibly portable. Legacy Windows emulation can surely be benefited from DOS emulation close at hand. Plus, it makes a decent processor emulator in a pinch. DOSBox is built in C. More about DOSBox at https://en.wikipedia.org/wiki/DOSBox
*A central coordinating service built in C++, which will connect sub-components to each other and make them work together. It will also probably be in charge of handling user IO (e.g., sending keyboard events into the application and displaying the graphics), emulating the file system (I have ideas about how to do this that would be better in our case than a virtual hard drive), and making/parsing code packages that can be transported between different instances of Peregrine.
*A GUI, probably built in C++ with the QT framework. I think it would be fun if it were a set of nested menus designed to resemble the Windows 9X start menu.

There are also a number of reimplimentations of Windows services packaged with ReactOS that will surely come in handy. I haven't looked through all of it yet, but there appears to be DirectX -- it will be tremendously convenient if we can run that natively and prepackage it with Peregrine instead of requiring users to download it seperately. We might also look into using Mono to natively run the CLR. This could represent a significant speed boost for .NET programs on non-x86 host platforms.

