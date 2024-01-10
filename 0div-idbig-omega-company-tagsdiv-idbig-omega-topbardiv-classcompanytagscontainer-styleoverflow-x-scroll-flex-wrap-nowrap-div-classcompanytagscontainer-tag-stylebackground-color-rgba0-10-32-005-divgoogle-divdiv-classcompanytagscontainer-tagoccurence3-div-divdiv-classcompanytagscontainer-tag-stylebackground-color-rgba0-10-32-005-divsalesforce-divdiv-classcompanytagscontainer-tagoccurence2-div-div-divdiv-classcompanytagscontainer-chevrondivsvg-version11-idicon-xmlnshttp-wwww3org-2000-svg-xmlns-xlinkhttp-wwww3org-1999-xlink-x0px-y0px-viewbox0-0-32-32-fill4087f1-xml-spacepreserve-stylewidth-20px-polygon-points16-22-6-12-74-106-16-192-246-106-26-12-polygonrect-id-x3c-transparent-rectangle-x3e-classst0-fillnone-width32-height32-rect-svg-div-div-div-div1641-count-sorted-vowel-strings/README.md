<h2><a href="https://leetcode.com/problems/count-sorted-vowel-strings/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Google</div><div class="companyTagsContainer--tagOccurence">3</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Salesforce</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1641. Count Sorted Vowel Strings</a></h2><h3>Medium</h3><hr><div><p>Given an integer <code>n</code>, return <em>the number of strings of length </em><code>n</code><em> that consist only of vowels (</em><code>a</code><em>, </em><code>e</code><em>, </em><code>i</code><em>, </em><code>o</code><em>, </em><code>u</code><em>) and are <strong>lexicographically sorted</strong>.</em></p>

<p>A string <code>s</code> is <strong>lexicographically sorted</strong> if for all valid <code>i</code>, <code>s[i]</code> is the same as or comes before <code>s[i+1]</code> in the alphabet.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> The 5 sorted strings that consist of vowels only are <code>["a","e","i","o","u"].</code>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 15
<strong>Explanation:</strong> The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> n = 33
<strong>Output:</strong> 66045
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code>&nbsp;</li>
</ul>
</div>