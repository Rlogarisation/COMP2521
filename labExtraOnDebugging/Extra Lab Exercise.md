<!DOCTYPE html>
<!-- saved from url=(0070)https://cgi.cse.unsw.edu.au/~cs2521/21T1/lab/extra/debugging/questions -->
<html lang="en"><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    
    <link rel="stylesheet" href="./COMP2521 21T1 - Extra Lab Exercise_files/bootstrap.min.css" integrity="sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z" crossorigin="anonymous">
    <link rel="stylesheet" href="./COMP2521 21T1 - Extra Lab Exercise_files/style.css">
    
    <title>COMP2521 21T1 - 

Extra Lab
Exercise

</title>
  <style shopback-extension-v6-2-6="" data-styled-version="4.2.0"></style><script type="text/javascript" async="" src="./COMP2521 21T1 - Extra Lab Exercise_files/MathJax.js.download"></script><style type="text/css">.MathJax_Hover_Frame {border-radius: .25em; -webkit-border-radius: .25em; -moz-border-radius: .25em; -khtml-border-radius: .25em; box-shadow: 0px 0px 15px #83A; -webkit-box-shadow: 0px 0px 15px #83A; -moz-box-shadow: 0px 0px 15px #83A; -khtml-box-shadow: 0px 0px 15px #83A; border: 1px solid #A6D ! important; display: inline-block; position: absolute}
.MathJax_Menu_Button .MathJax_Hover_Arrow {position: absolute; cursor: pointer; display: inline-block; border: 2px solid #AAA; border-radius: 4px; -webkit-border-radius: 4px; -moz-border-radius: 4px; -khtml-border-radius: 4px; font-family: 'Courier New',Courier; font-size: 9px; color: #F0F0F0}
.MathJax_Menu_Button .MathJax_Hover_Arrow span {display: block; background-color: #AAA; border: 1px solid; border-radius: 3px; line-height: 0; padding: 4px}
.MathJax_Hover_Arrow:hover {color: white!important; border: 2px solid #CCC!important}
.MathJax_Hover_Arrow:hover span {background-color: #CCC!important}
</style><style type="text/css">#MathJax_About {position: fixed; left: 50%; width: auto; text-align: center; border: 3px outset; padding: 1em 2em; background-color: #DDDDDD; color: black; cursor: default; font-family: message-box; font-size: 120%; font-style: normal; text-indent: 0; text-transform: none; line-height: normal; letter-spacing: normal; word-spacing: normal; word-wrap: normal; white-space: nowrap; float: none; z-index: 201; border-radius: 15px; -webkit-border-radius: 15px; -moz-border-radius: 15px; -khtml-border-radius: 15px; box-shadow: 0px 10px 20px #808080; -webkit-box-shadow: 0px 10px 20px #808080; -moz-box-shadow: 0px 10px 20px #808080; -khtml-box-shadow: 0px 10px 20px #808080; filter: progid:DXImageTransform.Microsoft.dropshadow(OffX=2, OffY=2, Color='gray', Positive='true')}
#MathJax_About.MathJax_MousePost {outline: none}
.MathJax_Menu {position: absolute; background-color: white; color: black; width: auto; padding: 2px; border: 1px solid #CCCCCC; margin: 0; cursor: default; font: menu; text-align: left; text-indent: 0; text-transform: none; line-height: normal; letter-spacing: normal; word-spacing: normal; word-wrap: normal; white-space: nowrap; float: none; z-index: 201; box-shadow: 0px 10px 20px #808080; -webkit-box-shadow: 0px 10px 20px #808080; -moz-box-shadow: 0px 10px 20px #808080; -khtml-box-shadow: 0px 10px 20px #808080; filter: progid:DXImageTransform.Microsoft.dropshadow(OffX=2, OffY=2, Color='gray', Positive='true')}
.MathJax_MenuItem {padding: 2px 2em; background: transparent}
.MathJax_MenuArrow {position: absolute; right: .5em; padding-top: .25em; color: #666666; font-size: .75em}
.MathJax_MenuActive .MathJax_MenuArrow {color: white}
.MathJax_MenuArrow.RTL {left: .5em; right: auto}
.MathJax_MenuCheck {position: absolute; left: .7em}
.MathJax_MenuCheck.RTL {right: .7em; left: auto}
.MathJax_MenuRadioCheck {position: absolute; left: 1em}
.MathJax_MenuRadioCheck.RTL {right: 1em; left: auto}
.MathJax_MenuLabel {padding: 2px 2em 4px 1.33em; font-style: italic}
.MathJax_MenuRule {border-top: 1px solid #CCCCCC; margin: 4px 1px 0px}
.MathJax_MenuDisabled {color: GrayText}
.MathJax_MenuActive {background-color: Highlight; color: HighlightText}
.MathJax_MenuDisabled:focus, .MathJax_MenuLabel:focus {background-color: #E8E8E8}
.MathJax_ContextMenu:focus {outline: none}
.MathJax_ContextMenu .MathJax_MenuItem:focus {outline: none}
#MathJax_AboutClose {top: .2em; right: .2em}
.MathJax_Menu .MathJax_MenuClose {top: -10px; left: -10px}
.MathJax_MenuClose {position: absolute; cursor: pointer; display: inline-block; border: 2px solid #AAA; border-radius: 18px; -webkit-border-radius: 18px; -moz-border-radius: 18px; -khtml-border-radius: 18px; font-family: 'Courier New',Courier; font-size: 24px; color: #F0F0F0}
.MathJax_MenuClose span {display: block; background-color: #AAA; border: 1.5px solid; border-radius: 18px; -webkit-border-radius: 18px; -moz-border-radius: 18px; -khtml-border-radius: 18px; line-height: 0; padding: 8px 0 6px}
.MathJax_MenuClose:hover {color: white!important; border: 2px solid #CCC!important}
.MathJax_MenuClose:hover span {background-color: #CCC!important}
.MathJax_MenuClose:hover:focus {outline: none}
</style><style type="text/css">.MathJax_Preview .MJXf-math {color: inherit!important}
</style><style type="text/css">.MJX_Assistive_MathML {position: absolute!important; top: 0; left: 0; clip: rect(1px, 1px, 1px, 1px); padding: 1px 0 0 0!important; border: 0!important; height: 1px!important; width: 1px!important; overflow: hidden!important; display: block!important; -webkit-touch-callout: none; -webkit-user-select: none; -khtml-user-select: none; -moz-user-select: none; -ms-user-select: none; user-select: none}
.MJX_Assistive_MathML.MJX_Assistive_MathML_Block {width: 100%!important}
</style><style type="text/css">#MathJax_Zoom {position: absolute; background-color: #F0F0F0; overflow: auto; display: block; z-index: 301; padding: .5em; border: 1px solid black; margin: 0; font-weight: normal; font-style: normal; text-align: left; text-indent: 0; text-transform: none; line-height: normal; letter-spacing: normal; word-spacing: normal; word-wrap: normal; white-space: nowrap; float: none; -webkit-box-sizing: content-box; -moz-box-sizing: content-box; box-sizing: content-box; box-shadow: 5px 5px 15px #AAAAAA; -webkit-box-shadow: 5px 5px 15px #AAAAAA; -moz-box-shadow: 5px 5px 15px #AAAAAA; -khtml-box-shadow: 5px 5px 15px #AAAAAA; filter: progid:DXImageTransform.Microsoft.dropshadow(OffX=2, OffY=2, Color='gray', Positive='true')}
#MathJax_ZoomOverlay {position: absolute; left: 0; top: 0; z-index: 300; display: inline-block; width: 100%; height: 100%; border: 0; padding: 0; margin: 0; background-color: white; opacity: 0; filter: alpha(opacity=0)}
#MathJax_ZoomFrame {position: relative; display: inline-block; height: 0; width: 0}
#MathJax_ZoomEventTrap {position: absolute; left: 0; top: 0; z-index: 302; display: inline-block; border: 0; padding: 0; margin: 0; background-color: white; opacity: 0; filter: alpha(opacity=0)}
</style><style type="text/css">.MathJax_Preview {color: #888}
#MathJax_Message {position: fixed; left: 1em; bottom: 1.5em; background-color: #E6E6E6; border: 1px solid #959595; margin: 0px; padding: 2px 8px; z-index: 102; color: black; font-size: 80%; width: auto; white-space: nowrap}
#MathJax_MSIE_Frame {position: absolute; top: 0; left: 0; width: 0px; z-index: 101; border: 0px; margin: 0px; padding: 0px}
.MathJax_Error {color: #CC0000; font-style: italic}
</style><style type="text/css">.MJXp-script {font-size: .8em}
.MJXp-right {-webkit-transform-origin: right; -moz-transform-origin: right; -ms-transform-origin: right; -o-transform-origin: right; transform-origin: right}
.MJXp-bold {font-weight: bold}
.MJXp-italic {font-style: italic}
.MJXp-scr {font-family: MathJax_Script,'Times New Roman',Times,STIXGeneral,serif}
.MJXp-frak {font-family: MathJax_Fraktur,'Times New Roman',Times,STIXGeneral,serif}
.MJXp-sf {font-family: MathJax_SansSerif,'Times New Roman',Times,STIXGeneral,serif}
.MJXp-cal {font-family: MathJax_Caligraphic,'Times New Roman',Times,STIXGeneral,serif}
.MJXp-mono {font-family: MathJax_Typewriter,'Times New Roman',Times,STIXGeneral,serif}
.MJXp-largeop {font-size: 150%}
.MJXp-largeop.MJXp-int {vertical-align: -.2em}
.MJXp-math {display: inline-block; line-height: 1.2; text-indent: 0; font-family: 'Times New Roman',Times,STIXGeneral,serif; white-space: nowrap; border-collapse: collapse}
.MJXp-display {display: block; text-align: center; margin: 1em 0}
.MJXp-math span {display: inline-block}
.MJXp-box {display: block!important; text-align: center}
.MJXp-box:after {content: " "}
.MJXp-rule {display: block!important; margin-top: .1em}
.MJXp-char {display: block!important}
.MJXp-mo {margin: 0 .15em}
.MJXp-mfrac {margin: 0 .125em; vertical-align: .25em}
.MJXp-denom {display: inline-table!important; width: 100%}
.MJXp-denom > * {display: table-row!important}
.MJXp-surd {vertical-align: top}
.MJXp-surd > * {display: block!important}
.MJXp-script-box > *  {display: table!important; height: 50%}
.MJXp-script-box > * > * {display: table-cell!important; vertical-align: top}
.MJXp-script-box > *:last-child > * {vertical-align: bottom}
.MJXp-script-box > * > * > * {display: block!important}
.MJXp-mphantom {visibility: hidden}
.MJXp-munderover, .MJXp-munder {display: inline-table!important}
.MJXp-over {display: inline-block!important; text-align: center}
.MJXp-over > * {display: block!important}
.MJXp-munderover > *, .MJXp-munder > * {display: table-row!important}
.MJXp-mtable {vertical-align: .25em; margin: 0 .125em}
.MJXp-mtable > * {display: inline-table!important; vertical-align: middle}
.MJXp-mtr {display: table-row!important}
.MJXp-mtd {display: table-cell!important; text-align: center; padding: .5em 0 0 .5em}
.MJXp-mtr > .MJXp-mtd:first-child {padding-left: 0}
.MJXp-mtr:first-child > .MJXp-mtd {padding-top: 0}
.MJXp-mlabeledtr {display: table-row!important}
.MJXp-mlabeledtr > .MJXp-mtd:first-child {padding-left: 0}
.MJXp-mlabeledtr:first-child > .MJXp-mtd {padding-top: 0}
.MJXp-merror {background-color: #FFFF88; color: #CC0000; border: 1px solid #CC0000; padding: 1px 3px; font-style: normal; font-size: 90%}
.MJXp-scale0 {-webkit-transform: scaleX(.0); -moz-transform: scaleX(.0); -ms-transform: scaleX(.0); -o-transform: scaleX(.0); transform: scaleX(.0)}
.MJXp-scale1 {-webkit-transform: scaleX(.1); -moz-transform: scaleX(.1); -ms-transform: scaleX(.1); -o-transform: scaleX(.1); transform: scaleX(.1)}
.MJXp-scale2 {-webkit-transform: scaleX(.2); -moz-transform: scaleX(.2); -ms-transform: scaleX(.2); -o-transform: scaleX(.2); transform: scaleX(.2)}
.MJXp-scale3 {-webkit-transform: scaleX(.3); -moz-transform: scaleX(.3); -ms-transform: scaleX(.3); -o-transform: scaleX(.3); transform: scaleX(.3)}
.MJXp-scale4 {-webkit-transform: scaleX(.4); -moz-transform: scaleX(.4); -ms-transform: scaleX(.4); -o-transform: scaleX(.4); transform: scaleX(.4)}
.MJXp-scale5 {-webkit-transform: scaleX(.5); -moz-transform: scaleX(.5); -ms-transform: scaleX(.5); -o-transform: scaleX(.5); transform: scaleX(.5)}
.MJXp-scale6 {-webkit-transform: scaleX(.6); -moz-transform: scaleX(.6); -ms-transform: scaleX(.6); -o-transform: scaleX(.6); transform: scaleX(.6)}
.MJXp-scale7 {-webkit-transform: scaleX(.7); -moz-transform: scaleX(.7); -ms-transform: scaleX(.7); -o-transform: scaleX(.7); transform: scaleX(.7)}
.MJXp-scale8 {-webkit-transform: scaleX(.8); -moz-transform: scaleX(.8); -ms-transform: scaleX(.8); -o-transform: scaleX(.8); transform: scaleX(.8)}
.MJXp-scale9 {-webkit-transform: scaleX(.9); -moz-transform: scaleX(.9); -ms-transform: scaleX(.9); -o-transform: scaleX(.9); transform: scaleX(.9)}
.MathJax_PHTML .noError {vertical-align: ; font-size: 90%; text-align: left; color: black; padding: 1px 3px; border: 1px solid}
</style></head>
  <body class="d-flex flex-column" style="min-height: 100vh;"><div id="MathJax_Message" style="display: none;"></div>
    <nav class="navbar fixed-top navbar-expand-lg navbar-light no-print" id="header-navbar">
      <div class="container">
        <button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navmenu" aria-controls="navmenu" aria-label="Toggle navigation" aria-expanded="false">
          <span class="navbar-toggler-icon"></span>
        </button>
    
        <a class="navbar-brand" href="https://webcms3.cse.unsw.edu.au/COMP2521/21T1">COMP2521 21T1</a>
    
        <div class="collapse navbar-collapse" id="navmenu">
          <ul class="navbar-nav mr-auto">
            <!--
            <li class="nav-item active"><a class="nav-link" href="#">Outline</a></li>
            <li class="nav-item active"><a class="nav-link" href="#">Forum</a></li>
            <li class="navbar-text px-2">|</li>
            -->

            
          </ul>
        </div>
      </div>
    </nav>
    
    
    <main class="container" aria-label="Content" style="flex: 1; padding-top: 4rem;">
      <header>
        <h1 class="text-center">
Extra Lab
Exercise
</h1>
        <h3 class="text-center">
Debugging with GDB and Valgrind
</h3>
        
      </header>
      <div class="text-justify mt-4">
        




<section class="exercise">
<header><h3>Objectives</h3></header>
<ul>
	<li>To learn about debugging with GDB</li>
	<li>To debug memory errors and leaks using Valgrind</li>
</ul>
</section>

<section class="exercise">
<header><h3>Admin</h3></header>
<p>This lab is not marked and there is no submission for it. However, we highly recommend that you attempt it so that you can use GDB and Valgrind in your future labs and assignments.</p>
</section>

<section class="exercise">
<header><h3>Resources</h3></header>
<p>You may want to consult the following resources:</p>
<ul>
	<li><a href="https://www.youtube.com/watch?v=5yZIFmplXsw" target="_blank">GDB Quickstart: Breakpoints and Printing Values</a></li>
	<li><a href="https://www.youtube.com/watch?v=OHUFeuBkBuI" target="_blank">Breaking, Stepping Over, and Stepping into Functions</a></li>
	<li><a href="https://www.youtube.com/watch?v=bWH-nL7v5F4" target="_blank">Debugging - GDB Tutorial (another great tutorial)</a></li>
</ul>
</section>

<section class="exercise">
<header><h3>Setting Up</h3></header>

<p>Create a directory for this lab, change into it, and run the following command:</p>

<pre is="tty"><kbd is="sh">unzip <a href="https://www.cse.unsw.edu.au/~cs2521/21T1/labs/extra/debugging/downloads/lab.zip">/web/cs2521/21T1/labs/extra/debugging/downloads/lab.zip</a></kbd>
</pre>

<p>If you're working at home, download <code>lab.zip</code> by clicking on the above link and then run the <code>unzip</code> command on the downloaded file.</p>

<p>If you've done the above correctly, you should now have the following files:</p>



<dl class="dl-horizontal">
	<dt><code><a href="https://www.cse.unsw.edu.au/~cs2521/21T1/labs/extra/debugging/files/Makefile">Makefile</a></code></dt>
	<dd>a set of dependencies used to control compilation</dd>
	<dt><code><a href="https://www.cse.unsw.edu.au/~cs2521/21T1/labs/extra/debugging/files/sorter.c">sorter.c</a></code></dt>
	<dd>a buggy program with a simple sorting function</dd>
	<dt><code><a href="https://www.cse.unsw.edu.au/~cs2521/21T1/labs/extra/debugging/files/Set.h">Set.h</a></code></dt>
	<dd>interface definition for a Set ADT</dd>
	<dt><code><a href="https://www.cse.unsw.edu.au/~cs2521/21T1/labs/extra/debugging/files/Set.c">Set.c</a></code></dt>
	<dd>buggy implementation of the Set ADT using a binary search tree</dd>
	<dt><code><a href="https://www.cse.unsw.edu.au/~cs2521/21T1/labs/extra/debugging/files/testSet.c">testSet.c</a></code></dt>
	<dd>main program for testing the Set ADT</dd>
</dl>

<p>If you run the <code>make</code> command, it will build two executables: <code>sorter</code> and <code>testSet</code>. Both of these programs are buggy. Before you fix the bugs in the programs, make copies of <code>sorter.c</code> and <code>Set.c</code> as follows:</p>

<pre is="tty"><kbd is="sh">cp sorter.c sorter.bad.c</kbd>
<kbd is="sh">cp Set.c Set.bad.c</kbd>
</pre>
</section>

<section class="exercise with-self">
<header><h3>Task 1 - Debugging the Sorter</h3></header>

<p>The aim of the sorter program is to generate a small array containing random numbers, print it, sort the array using bubble sort, and then print the sorted array. It repeats this process five times, generating different random array contents each time.</p>

<p>If the sorter were correct, you would observe something like the following:</p>

<pre is="tty"><kbd is="sh">./sorter</kbd>
Test #1
Sorting: 83 86 77 15 93 35 86 92 49 21
Sorted : 15 21 35 49 77 83 86 86 92 93
Test #2
Sorting: 62 27 90 59 63 26 40 26 72 36
Sorted : 26 26 27 36 40 59 62 63 72 90
Test #3
Sorting: 11 68 67 29 82 30 62 23 67 35
Sorted : 11 23 29 30 35 62 67 67 68 82
Test #4
Sorting: 29 02 22 58 69 67 93 56 11 42
Sorted : 02 11 22 29 42 56 58 67 69 93
Test #5
Sorting: 29 73 21 19 84 37 98 24 15 70
Sorted : 15 19 21 24 29 37 70 73 84 98
</pre>

<p>Unfortunately, what you actually observe is:</p>

<pre is="tty"><kbd is="sh">./sorter</kbd>
Test #1
Sorting: 83 86 77 15 93 35 86 92 49 21
<strong>Segmentation fault</strong>
</pre>

<p>You may get a different set of random numbers to the above, and maybe even a different error message depending on which machine you're working on, but that doesn't affect the exercise. The program should be able to sort any set of random numbers, but clearly there's a problem.</p>

<p>So, what to do...? You may have noticed that when the programs were compiled, they used the <code><b>-g</b></code> flag, which sets them up to be used with <b><code>gdb</code></b>. Run the program under control of <code>gdb</code> to find out where it is crashing.</p>

<pre is="tty"><kbd is="sh">gdb ./sorter</kbd>
GNU gdb (Debian 8.2.1-2+b3) 8.2.1
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later &lt;http://gnu.org/licenses/gpl.html&gt;
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
&lt;http://www.gnu.org/software/gdb/bugs/&gt;.
Find the GDB manual and other documentation resources online at:
    &lt;http://www.gnu.org/software/gdb/documentation/&gt;.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./sorter...done.
<kbd is="gdb">run</kbd>
Starting program: <var>some-long-path-name-ending-in</var>/sorter
...
Test #1
Sorting: 83 86 77 15 93 35 86 92 49 21

Program received signal SIGSEGV, Segmentation fault.
<span class="red">0x<var>XXX...XXX</var> in sort (a=0x<var>XXX...XXX</var>, n=10) at sorter.c:39
39				if (a[j] &lt; a[j - 1]) {</span>
<kbd is="gdb"></kbd>
</pre>

<p>where the <var>XXX...XXX</var> are large hexadecimal numbers, which may vary from machine to machine. The exact value is not important.</p>

<p>The <code>gdb</code> command can be quite verbose, and part of the skill of using it is working what to ignore. I've highlighted the critical output <span class="red">in red</span> above. If the long header annoys you, simply use the <b><code>-q</code></b> option:</p>

<pre is="tty"><kbd is="sh">gdb -q ./sorter</kbd>
Reading symbols from ./sorter...done.
<kbd is="gdb"></kbd>
</pre>
<p>In the sample output above, you can see the line where the error has occured. Sometimes it's useful to get more context than just a single line. You can do this from within <code>gdb</code> using the <code>list</code> command, e.g.</p>

<pre is="tty"><kbd is="gdb">list</kbd>
34	{
35		int i, j, nswaps;
36		for (i = 0; i &lt; n; i++) {
37			nswaps = 0;
38			for (j = n - 1; j &gt; i; j++) {
39				if (a[j] &lt; a[j - 1]) {
40					int tmp;
41					tmp = a[j];
42					a[j] = a[j - 1];
43					a[j - 1] = tmp;
<kbd is="gdb"></kbd>
</pre>

<p>An alternative to using <code>list</code> is simply to keep the program open in an edit window while you run <code>gdb</code> in a separate window. GDB also provides a mode so that you can monitor the code and do debugging in a single terminal window; run the <code>gdb</code> command with the <code>-tui</code> option. Yet another alternative is to use a program like <code>ddd</code>, which provides a GUI front-end to <code>gdb</code>. For this lab, it may be simpler to stick with plain <code>gdb</code>, which has the advantage that it will be available on all Linux machines.</p>

<p>Use <code>gdb</code> to find out more information about the state of the program at the point where it crashed. You can find out about the current state of your program in <code>gdb</code> using commands like <code>where</code> and <code>print</code>:</p>

<pre is="tty"><kbd is="gdb">where</kbd>        <span class="comment">// verify where the program was executing when it crashed</span>
...                <span class="comment">// - gdb gave you a line number above; this will tell you which function</span>
<kbd is="gdb">print n</kbd>      <span class="comment">// show the value of the parameter 'n'</span>
...
<kbd is="gdb">print a</kbd>      <span class="comment">// show the value of the parameter 'a'</span>
...                <span class="comment">// - this is the address of the start of the array</span>
<kbd is="gdb">print *a</kbd>     <span class="comment">// show the first element in the array</span>
...
<kbd is="gdb">print a[0]</kbd>   <span class="comment">// show the first element in the array</span>
...
<kbd is="gdb">print a[2]</kbd>   <span class="comment">// show the third element in the array</span>
...
<kbd is="gdb">print *a@5</kbd>   <span class="comment">// show the first 5 elements in the array</span>
...
<kbd is="gdb">print a[j]</kbd>   <span class="comment">// show the j'th element of the array</span>
...
</pre>

<p>Keep examining variables until you find something that looks anomalous. You will then need to find out how it got that way. You could look at the code again and you might spot the error. If not,
continue...</p>

<p>One useful way to find out how your program reached its current erroneous state, is to set a breakpoint on the <code>sort</code> function and observe the behaviour as that function executes.</p>

<pre is="tty"><kbd is="gdb">break sort</kbd>
...
<kbd is="gdb">run</kbd>
...                <span class="comment">// stops at breakpoint ... start of sort function</span>
<kbd is="gdb">next</kbd>
...                <span class="comment">// execute next statement, then check variable values</span>
<kbd is="gdb">next</kbd>
...
</pre>

<p>If examining the variables at each step doesn't help you to find the problem quickly, then try adding a breakpoint on line 39 (where the error occurs), and re-running the program. After it stops each time, check the value of variables. After each stop/check, you can continue the program with the <b><code>continue</code></b> command.</p>

<p>Once you've found the problem, change the code to try to fix it, recompile, and see whether the program now exhibits the expected behaviour.</p>

</section>

<section class="exercise with-self">
<header><h3>Task 2 - Debugging the Set</h3></header>

<p>If you simply compile the <code>testSet</code> program without change, it will behave as follows:</p>

<pre is="tty"><kbd is="sh">./testSet</kbd>
Test 1: Create set
Passed
Test 2: Add to set
Segmentation fault
</pre>

<p>Note that this program uses assertions to aid debugging. While assertions provide some information, they may not provide enough to work out what the problem is (e.g. "what is the value of variable <code>i</code>?").</p>

<p>Now run the program under <code>gdb</code>'s control, observe the values of variables when it crashes, and use this information to determine the causes of the problems.</p>

<p>Note that <b>this program has multiple bugs</b>, so after you fixed one, another will probably manifest itself when you recompile and test. Repeat the above until <code>testSet</code> exhibits the expected behaviour.</p>

<p>Once the Set ADT has been implemented correctly, then the <code>testSet</code> program should produce something like the following:</p>

<pre is="tty"><kbd is="sh">./testSet</kbd>
Test 1: Create set
Passed
Test 2: Add to set
Passed
Test 3: Add duplicates
Passed
Test 4: Add more to set
Passed
Test 5: Print set
{2, 4, 6, 7, 9}
Check manually
Test 6: Free set
Now check for memory errors and leaks using valgrind
</pre>

<p>Note that even though a program behaves as expected, this does not guarantee that the code is correct. The code may contain memory errors, which occur when your program tries to read from or write to a memory location that it shouldn't. The code may also contain memory leaks, which occur when your program dynamically allocates memory (using <i>malloc</i>), but doesn't free it once it's no longer needed. Memory errors are more difficult to debug, as they don't always manifest themselves, so a program with memory errors may run normally one time, but abnormally the next. They also often lead to strange behaviour that occurs far away from the source of the actual problem.</p>

<p>Run the program in <code>valgrind</code> to see if the code contains any memory errors or leaks. If your code <i>does</i> contain memory errors or leaks, you might get output that looks like the following:</p>

<pre is="tty"><kbd is="sh">valgrind ./testSet</kbd>
==15336== Memcheck, a memory error detector
==15336== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==15336== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==15336== Command: ./testSet
==15336== 
Test 1: Create set
==15336== Invalid write of size 4
==15336==    at 0x1098A4: SetNew (Set.c:38)
==15336==    by 0x1091BD: main (testSet.c:18)
==15336==  Address 0x4a43488 is 0 bytes after a block of size 8 alloc'd
==15336==    at 0x48357BF: malloc (vg_replace_malloc.c:299)
==15336==    by 0x10985F: SetNew (Set.c:31)
==15336==    by 0x1091BD: main (testSet.c:18)
...
...
...
==15336== HEAP SUMMARY:
==15336==     in use at exit: 56 bytes in 3 blocks
==15336==   total heap usage: 7 allocs, 4 frees, 1,152 bytes allocated
==15336== 
==15336== LEAK SUMMARY:
==15336==    definitely lost: 56 bytes in 3 blocks
==15336==    indirectly lost: 0 bytes in 0 blocks
==15336==      possibly lost: 0 bytes in 0 blocks
==15336==    still reachable: 0 bytes in 0 blocks
==15336==         suppressed: 0 bytes in 0 blocks
==15336== Rerun with --leak-check=full to see details of leaked memory
==15336== 
==15336== For counts of detected and suppressed errors, rerun with: -v
==15336== ERROR SUMMARY: 19 errors from 19 contexts (suppressed: 0 from 0)
</pre>

<p>Valgrind gives detailed information of memory errors. If your program tried to read from an invalid memory location, Valgrind will report an invalid read. If your program tried to write to an invalid memory location, Valgrind will report an invalid write and tell you the size of the data item that your program wrote. In the above example, Valgrind reported an 'Invalid write of size 4', which means the program likely tried to write an <code>int</code> to an invalid memory address (since an <code>int</code> is 4 bytes). Valgrind will also tell you the line on which the error occurred. For example, <code>(Set.c:38)</code> means Line 38 in <code>Set.c</code>.</p>

<p>From this output, it is up to you to figure out the cause of the error and fix it. Here are some common causes of memory errors:</p>

<ul>
	<li>Not allocating enough memory - this is common with strings</li>
	<li>Trying to access an index beyond the end of an array</li>
	<li>Reading and using an uninitialised value</li>
	<li>Use after free - this is where you free a block memory and then try to access it afterwards.</li>
	<li>Double free - this is where you free the same block of memory twice.
</li></ul>

<p>Valgrind also summarises memory leaks. You can get more detailed information about memory leaks by using the <code>--leak-check=full</code> option, as the output above suggests.</p>

<pre is="tty"><kbd is="sh">valgrind --leak-check=full ./testSet</kbd>
...
...
...
==15280== 
==15280== HEAP SUMMARY:
==15280==     in use at exit: 56 bytes in 3 blocks
==15280==   total heap usage: 7 allocs, 4 frees, 1,152 bytes allocated
==15280== 
==15280== 8 bytes in 1 blocks are definitely lost in loss record 1 of 3
==15280==    at 0x48357BF: malloc (vg_replace_malloc.c:299)
==15280==    by 0x10985F: SetNew (Set.c:31)
==15280==    by 0x1091BD: main (testSet.c:18)
==15280== 
==15280== 24 bytes in 1 blocks are definitely lost in loss record 2 of 3
==15280==    at 0x48357BF: malloc (vg_replace_malloc.c:299)
==15280==    by 0x1099F7: newNode (Set.c:80)
==15280==    by 0x109982: doSetAdd (Set.c:68)
==15280==    by 0x1099D1: doSetAdd (Set.c:74)
==15280==    by 0x1099D1: doSetAdd (Set.c:74)
==15280==    by 0x109944: SetAdd (Set.c:61)
==15280==    by 0x1095B2: main (testSet.c:66)
==15280== 
==15280== 24 bytes in 1 blocks are definitely lost in loss record 3 of 3
==15280==    at 0x48357BF: malloc (vg_replace_malloc.c:299)
==15280==    by 0x1099F7: newNode (Set.c:80)
==15280==    by 0x109982: doSetAdd (Set.c:68)
==15280==    by 0x1099A4: doSetAdd (Set.c:72)
==15280==    by 0x1099D1: doSetAdd (Set.c:74)
==15280==    by 0x109944: SetAdd (Set.c:61)
==15280==    by 0x1095C3: main (testSet.c:67)
==15280== 
==15280== LEAK SUMMARY:
==15280==    definitely lost: 56 bytes in 3 blocks
==15280==    indirectly lost: 0 bytes in 0 blocks
==15280==      possibly lost: 0 bytes in 0 blocks
==15280==    still reachable: 0 bytes in 0 blocks
==15280==         suppressed: 0 bytes in 0 blocks
==15280== 
==15280== For counts of detected and suppressed errors, rerun with: -v
==15280== ERROR SUMMARY: 22 errors from 22 contexts (suppressed: 0 from 0)
</pre>

<p>Valgrind will tell you where the memory that was leaked was allocated. From there, you should be able to figure out why you aren't freeing the memory and where you should be freeing it.</p>

<p>Once you have fixed all the memory errors and leaks, Valgrind should output something like the following:</p>

<pre is="tty"><kbd is="sh">valgrind ./testSet</kbd>
==22805== Memcheck, a memory error detector
==22805== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==22805== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==22805== Command: ./testSet
==22805== 
Test 1: Create set
Passed
Test 2: Add to set
Passed
Test 3: Add duplicates
Passed
Test 4: Add more to set
Passed
Test 5: Print set
{2, 4, 6, 7, 9}
Check manually
Test 6: Free set
Now check for memory errors and leaks using valgrind
==22805== 
==22805== HEAP SUMMARY:
==22805==     in use at exit: 0 bytes in 0 blocks
==22805==   total heap usage: 7 allocs, 7 frees, 1,160 bytes allocated
==22805== 
==22805== All heap blocks were freed -- no leaks are possible
==22805== 
==22805== For counts of detected and suppressed errors, rerun with: -v
==22805== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
</pre>

</section>





      </div>
    </main>

    <footer class="mt-3 py-3 bg-dark text-center no-print">
      <p class="text-muted">
        <small>
          <strong>COMP2521 21T1: Data Structures and Algorithms</strong>
          is brought to you by <br>
          the <a href="https://www.cse.unsw.edu.au/">School of Computer Science and Engineering</a><br>
          at the <a href="https://www.unsw.edu.au/">University of New South Wales</a>, Sydney.<br>
          For all enquiries, please email the class account at
          <a href="mailto:cs2521@cse.unsw.edu.au">cs2521@cse.unsw.edu.au</a><br>
          
          CRICOS Provider 00098G
        </small>
      </p>
    </footer>
    
    <script src="./COMP2521 21T1 - Extra Lab Exercise_files/jquery-3.5.1.slim.min.js.download" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
    <script src="./COMP2521 21T1 - Extra Lab Exercise_files/popper.min.js.download" integrity="sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN" crossorigin="anonymous"></script>
    <script src="./COMP2521 21T1 - Extra Lab Exercise_files/bootstrap.min.js.download" integrity="sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV" crossorigin="anonymous"></script>
    
    <!-- math -->
    <script src="./COMP2521 21T1 - Extra Lab Exercise_files/latest.js.download" async=""></script>
  
</body><div id="shopback-app" style="z-index: 2147483647 !important;"></div></html>
