# PlotSched

Scheduling traces plotter

* Under development, November 2015

----
## Authors

* Alessio Balsini (a.balsini@sssup.it)

License: GPL 2.0

----
## Introduction

PlotSched is a flexible tool for graphically showing (general) events stored in a file.

It was born by the need of having a flexible and straightforward tool for quickly showing the scheduler behavior.

----

## Instructions

In the following sections are presented the steps required for compiling the tool and the instructions for running it.

### Dependencies

This tool requires the Qt sdk.

### Compiling

Being a Qt project, it is required to generate the makefile.
Enter into directory `src/` and type:

```
qmake test.pro
```

This produces the makefile file `Makefile`, that can be directly used for compiling:

```
make
```

Now, the executable `PlotSched` is generated and can be run:

```
./PlotSched
```

### Usage

The file extension is `.pst` (Plot Sched Trace).

The file format used by `PlotSched` is the following:

```
<time> <entity> <CPU> <event name> <event status>
```

Where:
* `time` is the time at which the event is generated;
* `entity` is the subject that generated the event;
* `CPU` is the CPU on which the entity was running;
* `event name` is the event identifier;
* `event status` is the kind of event and can be:
  * `I` for instantaneous events (that start and finish at the same time);
  * `S` defining that an event just started;
  * `E` defining that an event just finished;


The tool recognizes any row as an event.

Examples of `.pst` files can be found in `examples/` folder.
