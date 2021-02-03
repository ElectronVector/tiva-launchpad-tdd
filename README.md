# A Test-Driven Development Environment for the Tiva C Series Launchpad

This is an example project and build environment for the Tiva C Series Launchpad (EK-TM4C123GXL). It demonstrates how to use the Ceedling unit test framework to facilitate test-driven design.

## Tiva Launchpad

The [Tiva C Series Launchpad (EK-TM4C123GXL)](http://www.ti.com/ww/en/launchpad/launchpads-connected-ek-tm4c123gxl.html) is a low-cost evaluation board from TI for their powerful line of ARM Cortex-M4F-based microcontrollers. You can get it for [about $13](https://store.ti.com/Tiva-C-LaunchPad.aspx).

Tiva C Series Launchpad (EK-TM4C123GXL):

<img src="launchpad-tivac.jpg" width="400">

## Requirements

This build environment requires that [Vagrant](http://www.vagrantup.com/downloads) and [Virtualbox](https://www.virtualbox.org/wiki/Downloads) are installed. Virtualbox 5.0 adds support for USB 3.0. **I've tested this setup working on USB 3.0 ports with Virtualbox 5.0.4!** I had previously been unable to get it working with version 5.0.0.

## Starting the Environment

Launch the environment with: `vagrant up`.

Connect to it with: `vagrant ssh`.

Exit the environment with `exit`.

## Building and Loading the Example Project

The example project is in the **example-project** folder. Switch to this folder to run the example project commands.

Execute all unit tests with `ceedling test:all`.

Run a single test with `ceedling test:<module>`, e.g. `ceedling test:led`.

Load the app on the board with: `ceedling load`.

The load command also builds the application if necessary. Just build the application with: `ceedling release`.

## Example Project Description

Included with this environment is an example project with unit tests. When loaded and run the Launchpad LED flashes -- switching between red, green and blue.

The example project source is in **example-project/src**. The main loop in main.c drives the application.

There are two software modules -- **state** and **led** -- used to determine the LED color (the state) and to set the color of the LED. Each of these modules implements units tests. Unit tests are in **example-project/test**.

In the **led** module, the TivaWare Peripheral Driver Library is used to initialize and control the GPIO pins connected the multi-color LED. This library is in **lib/TivaWare/driverlib** and is built automatically if necessary.

## Documentation

[Ceedling Manual](https://github.com/ThrowTheSwitch/Ceedling/blob/master/docs/CeedlingPacket.md)

[CMock Manual](https://github.com/ThrowTheSwitch/CMock/blob/master/docs/CMock_Summary.md)

[Unity Manual](https://github.com/ThrowTheSwitch/Unity/raw/master/docs/Unity%20Summary.pdf)
