# Obfuscated-Keylogger
Keylogger and a simple method for encode (Base64) and encryption.        

<ul>
  <li><a href="#introduccion-al-proyecto">Introduction to the proyect</a></li>
  <li><a href="#implementaci%C3%B3n-del-proyecto">Project implementation</a></li>
  <li><a href="#instructions">Instructions</a></li>
</ul>

<h2><a id="user-content-introduccion-al-proyecto" class="anchor" aria-hidden="true" href="#introduccion-al-proyecto"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Introduction to the proyect</h2>

I am a great lover of computer security, and programming allows me to create tools that help me understand through the 'creation' process. My goal here is to implement a simple method to obfuscate code by keywords, the user must provide these words and the files to be obfuscated, the program will return an obfuscated version of each file, simple but powerful.

<h2><a id="user-content-implementación-del-proyecto" class="anchor" aria-hidden="true" href="#implementación-del-proyecto"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Project implementation</h2>

<ul>
<li><strong>C++ 17</strong>: The language and version used to develop this program.</li>
<li><strong>Microsoft Visual Studio 2017</strong>: IDE Used to debug and compile.</li>
<li><strong>x64</strong>: Architecture in which the program is focused.</li>
<li><strong>GMX E-mail Service</strong>: I need to do a little trick to register from Argentina.</li>
</ul>

First the Keylogger, it is easy to understand, it uses a simple method to hook the keys when they are pressed, then it stores our pressed keys in an encrypted file, sends it in an email to the attacker and that is all. We have 3 layers here, obfuscation, base64 encode and encryptation with salts. 

<h2><a id="user-content-instructions" class="anchor" aria-hidden="true" href="#instructions"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Instructions</h2>

Instructions:                                                                                                                                                            
<pre><code>We must set our own salts and make them match (Base64.h and decrypter.cpp).
</code></pre>

<pre><code>Establish the email address and password to which encrypted / encrypted messages will be sent. 
</code></pre>                                                                           

<pre><code>Set the time interval between messages (keyhook.h) on line 37.
</code></pre>     

<pre><code>Obfuscate the code using the obfuscator. Put the words you want to obfuscate in the array, the same for files.
</code></pre>                                                                             

I didn't take the time to make the script functional. It is understood that whoever is going to use this must first understand how C ++ works.                                                                                                                                                     
