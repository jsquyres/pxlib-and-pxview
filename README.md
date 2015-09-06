This project started out as a direct import of the pxlib library and
pxview tool, written by Uwe Steinmann, downloaded from:

> http://pxlib.sourceforge.net/ <br />
> http://pxlib.sourceforge.net/pxview.html

I made a repo for both of these just so that I could apply my own
minor modernizations and updates (e.g., so that I can get (semi-)clean
builds with modern GNU Autotools and compilers in September of 2015).

However, I've made a few more than "minor" adjustments:

* Combined both into a single package (i.e., single configure/build
  system), because they go together like peanut butter and jelly.
* Added a few bug fixes here and there.

(I still don't think I have the i18n stuff right yet, but maybe I'll
fix that over time...)

What is pxlib?
--------------

pxlib is shared C library to read various Paradox files. Currently .DB
files are best supported.  pxlib provides a very simple API to read
the header and the data records of Paradox files.  It also provides
functions to convert the data into the host's data format (little or
big endian).

The complete API is well documented in set of man pages, one for each
function.

What is pxview?
---------------

pxview is a quite simple command line program which has been
originally created to test pxlib.  During the development, pxview
evolved more and more into a useful program to examine the contents of
Paradox files and to convert them into SQL or CSV formats.

At the current stage, it can not read all of the different Paradox
files, but it is quite good at reading .DB files.

For a more detailed documentation read the man page pxview(1) and
check the original web site at http://pxlib.sourceforge.net.
