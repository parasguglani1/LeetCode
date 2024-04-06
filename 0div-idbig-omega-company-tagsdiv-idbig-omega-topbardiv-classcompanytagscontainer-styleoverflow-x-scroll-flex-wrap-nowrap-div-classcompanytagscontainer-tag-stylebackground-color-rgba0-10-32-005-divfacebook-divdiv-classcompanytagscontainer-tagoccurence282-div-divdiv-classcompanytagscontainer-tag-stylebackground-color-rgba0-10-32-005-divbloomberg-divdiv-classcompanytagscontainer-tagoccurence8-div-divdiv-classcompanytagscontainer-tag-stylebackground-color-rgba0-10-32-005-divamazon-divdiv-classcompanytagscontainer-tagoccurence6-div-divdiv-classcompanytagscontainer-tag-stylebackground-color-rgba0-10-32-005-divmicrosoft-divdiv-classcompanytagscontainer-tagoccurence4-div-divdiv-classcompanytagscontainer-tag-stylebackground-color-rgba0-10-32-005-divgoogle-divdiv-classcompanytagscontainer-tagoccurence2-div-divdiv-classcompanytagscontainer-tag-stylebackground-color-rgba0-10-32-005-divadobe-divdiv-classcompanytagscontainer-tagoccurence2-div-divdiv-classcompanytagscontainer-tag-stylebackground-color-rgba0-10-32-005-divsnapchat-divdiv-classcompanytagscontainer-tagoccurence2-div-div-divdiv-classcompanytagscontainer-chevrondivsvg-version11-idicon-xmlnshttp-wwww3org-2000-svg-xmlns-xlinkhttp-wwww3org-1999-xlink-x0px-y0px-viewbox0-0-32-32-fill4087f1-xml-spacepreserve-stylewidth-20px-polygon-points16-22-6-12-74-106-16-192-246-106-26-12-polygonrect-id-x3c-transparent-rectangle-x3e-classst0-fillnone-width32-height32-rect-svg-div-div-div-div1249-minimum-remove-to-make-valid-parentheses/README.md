<h2><a href="https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Facebook</div><div class="companyTagsContainer--tagOccurence">282</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Bloomberg</div><div class="companyTagsContainer--tagOccurence">8</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Amazon</div><div class="companyTagsContainer--tagOccurence">6</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Microsoft</div><div class="companyTagsContainer--tagOccurence">4</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Google</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Adobe</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Snapchat</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1249. Minimum Remove to Make Valid Parentheses</a></h2><h3>Medium</h3><hr><div><p>Given a string <font face="monospace">s</font> of <code>'('</code> , <code>')'</code> and lowercase English characters.</p>

<p>Your task is to remove the minimum number of parentheses ( <code>'('</code> or <code>')'</code>, in any positions ) so that the resulting <em>parentheses string</em> is valid and return <strong>any</strong> valid string.</p>

<p>Formally, a <em>parentheses string</em> is valid if and only if:</p>

<ul>
	<li>It is the empty string, contains only lowercase characters, or</li>
	<li>It can be written as <code>AB</code> (<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are valid strings, or</li>
	<li>It can be written as <code>(A)</code>, where <code>A</code> is a valid string.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "lee(t(c)o)de)"
<strong>Output:</strong> "lee(t(c)o)de"
<strong>Explanation:</strong> "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "a)b(c)d"
<strong>Output:</strong> "ab(c)d"
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "))(("
<strong>Output:</strong> ""
<strong>Explanation:</strong> An empty string is also valid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either<code>'('</code> , <code>')'</code>, or lowercase English letter<code>.</code></li>
</ul>
</div>