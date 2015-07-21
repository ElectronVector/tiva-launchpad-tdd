# Example Ceedling project for the Tiva Launchpad

*With Vagrant build environment!*

This is an example project and build environment for the Tiva C Series Launchpad (EK-TM4C123GXL). It demonstrates how to use the Ceedling unit test framework to facilitate test-driven design.

The [Tiva C Series Launchpad (EK-TM4C123GXL)](http://www.ti.com/ww/en/launchpad/launchpads-connected-ek-tm4c123gxl.html) is a low-cost evaluation board from TI. You can get it for [about $13](https://store.ti.com/Tiva-C-LaunchPad.aspx). It's built for their line of Tiva C Series microcontrollers, which are powerful ARM Cortex-M4F-based microcontrollers.

Tiva C Series Launchpad (EK-TM4C123GXL)
<img src="launchpad-tivac.jpg" width="400">

Launch the environment with: `vagrant up`

Connect to it with: `vagrant ssh`

Load the app on the board with: `rake load`

# Documentation

[Ceedling Manual](https://github.com/ThrowTheSwitch/Ceedling/blob/master/docs/CeedlingPacket.md)

[CMock Manual](https://github.com/ThrowTheSwitch/CMock/blob/master/docs/CMock_Summary.md)

[Unity Manual](https://github.com/ThrowTheSwitch/Unity/raw/master/docs/Unity%20Summary.pdf)
