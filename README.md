# Arduino 4-Bit Hexadecimal 7-Segment Display

RBT173 lab project: Four digital switches represent a 4-bit binary value (0–15). An Arduino Uno reads the switches and drives a common-anode, active-low 7-segment display to show 0–9 and A–F.

## Files
- `Seven_Segment_Display.ino` — Arduino source code from the submitted lab report
- `circuit_diagram.png` — Original circuit schematic extracted from the Word lab report
- `Seven_Segment_Display_Lab_Report.pdf` — Submitted report with additional circuit photos and discussion

## Wiring
- Binary switches (1, 2, 4, 8): D12, D11, D10, D9
- Segments A–G: D2–D8
- Common-anode display: segments illuminate when driven LOW; use current-limiting resistors

## Demonstration
https://youtu.be/2-9XP0s7n-E

**Note:** Code and schematic reflect the submitted lab. Compilation and hardware testing have not been independently repeated for this package.
