# link

- [C type총정리 굿..이것만 공부해도 되겠네 ㅋ](#c-type)
  - https://en.wikipedia.org/wiki/C_data_types

- [C언어에서 `int main(int argc, char* argc[])` 의미](#c언어에서-int-mainint-argc-char-argc-의미)

<hr />

# eBook(C)[|🔝|](#link)
- https://colorcomputerarchive.com/repo/Documents/Books/The%20C%20Programming%20Language%20%28Kernighan%20Ritchie%29.pdf
  - [freeCodeCamp.org(C/C++ 강의 시리즈 영상 많다.)](https://youtube.com/playlist?list=PLWKjhJtqVAbmUE5IqyfGYEYjrZBYzaT4m&si=OPDO7vwocp6LrCdX)

- [(251007) Learn C from scratch - One course to rule them all | dr Jonas Birch](https://youtu.be/wzMaNVSqfYw?si=6xW8IYDXLdMeewM3)
  - 코드 https://repo.doctorbirch.com/roadmap/

# build(c23)[|🔝|](#link)
- https://github.com/YoungHaKim7/c23_pthread_cmake_just_sample

# Compiler (Assembly 분석하기 좋다.)[|🔝|](#link)
- https://godbolt.org/

# Code snippets for C/C++ for VS Code[|🔝|](#link)
- https://github.com/one-harsh/vscode-cpp-snippets

# fprint[|🔝|](#link)
- https://en.cppreference.com/w/c/io/fprintf

# C type[|🔝|](#link)
- https://en.wikipedia.org/wiki/C_data_types

- Good examples using 'union' with 'enum'?
  - https://stackoverflow.com/questions/25926862/good-examples-using-union-with-enum

<table>
  

<tbody><tr>
<th>Type
</th>
<th>Explanation
</th>
<th>Size (bits)<sup id="cite_ref-3" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-3"><span class="cite-bracket">[</span>a<span class="cite-bracket">]</span></a></sup>
</th>
<th>Format specifier
</th>
<th>Range
</th>
<th>Suffix for decimal constants
</th></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">bool</span></td>
<td>Boolean type, added in <a href="https://en.wikipedia.org/wiki/C23_(C_standard_revision)" title="C23 (C standard revision)">C23</a>. (Previously <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">_Bool</span> added in <a href="https://en.wikipedia.org/wiki/C99" title="C99">C99</a>,<sup id="cite_ref-4" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-4"><span class="cite-bracket">[</span>3<span class="cite-bracket">]</span></a></sup> but its size and its range were not specified.)</td>
<td>1 (exact)</td>
<td><code>%d</code></td>
<td>[<link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">false</span>, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">true</span>]</td>
<td data-sort-value="" style="background: var(--background-color-interactive, #ececec); color: var(--color-base, inherit); vertical-align: middle; text-align: center;" class="table-na">—
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">char</span></td>
<td>Smallest addressable unit of the machine that can contain basic character set. It is an <a href="https://en.wikipedia.org/wiki/Integer_(computer_science)" title="Integer (computer science)">integer</a> type. Actual type can be either signed or unsigned. It contains <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">CHAR_BIT</span> bits.<sup id="cite_ref-c99sizes_5-0" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99sizes-5"><span class="cite-bracket">[</span>4<span class="cite-bracket">]</span></a></sup></td>
<td>≥8</td>
<td><code>%c</code></td>
<td>[<link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">CHAR_MIN</span>, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">CHAR_MAX</span>]</td>
<td data-sort-value="" style="background: var(--background-color-interactive, #ececec); color: var(--color-base, inherit); vertical-align: middle; text-align: center;" class="table-na">—
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">signed char</span></td>
<td>Of the same size as <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">char</span>, but guaranteed to be signed. Capable of containing at least the <span class="texhtml texhtml-big" style="font-size:100%;">[−127, +127]</span> range.<sup id="cite_ref-c99sizes_5-1" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99sizes-5"><span class="cite-bracket">[</span>4<span class="cite-bracket">]</span></a></sup><sup id="cite_ref-restr_8-0" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-restr-8"><span class="cite-bracket">[</span>b<span class="cite-bracket">]</span></a></sup></td>
<td>≥8</td>
<td><code>%c</code><sup id="cite_ref-9" class="reference"><a href="#cite_note-9"><span class="cite-bracket">[</span>c<span class="cite-bracket">]</span></a></sup></td>
<td>[<link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">SCHAR_MIN</span>, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">SCHAR_MAX</span>]<sup id="cite_ref-10" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-10"><span class="cite-bracket">[</span>7<span class="cite-bracket">]</span></a></sup></td>
<td data-sort-value="" style="background: var(--background-color-interactive, #ececec); color: var(--color-base, inherit); vertical-align: middle; text-align: center;" class="table-na">—
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">unsigned char</span></td>
<td>Of the same size as <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">char</span>, but guaranteed to be unsigned. Contains at least the <span class="texhtml texhtml-big" style="font-size:100%;">[0, 255]</span> range.<sup id="cite_ref-c99generalrepr_11-0" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99generalrepr-11"><span class="cite-bracket">[</span>8<span class="cite-bracket">]</span></a></sup></td>
<td>≥8</td>
<td><code>%c</code><sup id="cite_ref-12" class="reference"><a href="#cite_note-12"><span class="cite-bracket">[</span>d<span class="cite-bracket">]</span></a></sup></td>
<td>[0, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">UCHAR_MAX</span>]</td>
<td data-sort-value="" style="background: var(--background-color-interactive, #ececec); color: var(--color-base, inherit); vertical-align: middle; text-align: center;" class="table-na">—
</td></tr>
<tr>
<td><div class="plainlist">
<ul><li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">short</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">short int</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">signed short</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">signed short int</span></li></ul>
</div>
</td>
<td><i>Short</i> signed integer type. Capable of containing at least the <span class="texhtml texhtml-big" style="font-size:100%;">[<span class="nowrap"><span data-sort-value="2995672330000000000♠"></span>−32<span style="margin-left:.25em;">767</span></span>, <span class="nowrap"><span data-sort-value="7004327670000000000♠"></span>+32<span style="margin-left:.25em;">767</span></span>]</span> range.<sup id="cite_ref-c99sizes_5-2" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99sizes-5"><span class="cite-bracket">[</span>4<span class="cite-bracket">]</span></a></sup><sup id="cite_ref-restr_8-1" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-restr-8"><span class="cite-bracket">[</span>b<span class="cite-bracket">]</span></a></sup></td>
<td>≥16</td>
<td><code>%hi</code> or <code>%hd</code></td>
<td>[<link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">SHRT_MIN</span>, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">SHRT_MAX</span>]</td>
<td data-sort-value="" style="background: var(--background-color-interactive, #ececec); color: var(--color-base, inherit); vertical-align: middle; text-align: center;" class="table-na">—
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r1126788409"><div class="plainlist">
<ul><li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">unsigned short</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">unsigned short int</span></li></ul>
</div>
</td>
<td><i>Short</i> unsigned integer type. Contains at least the <span class="texhtml texhtml-big" style="font-size:100%;">[<span class="nowrap"><span data-sort-value="5000000000000000000♠"></span>0</span>, <span class="nowrap"><span data-sort-value="7004655350000000000♠"></span>65<span style="margin-left:.25em;">535</span></span>]</span> range.<sup id="cite_ref-c99sizes_5-3" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99sizes-5"><span class="cite-bracket">[</span>4<span class="cite-bracket">]</span></a></sup></td>
<td>≥16</td>
<td><code>%hu</code></td>
<td>[0, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">USHRT_MAX</span>]</td>
<td data-sort-value="" style="background: var(--background-color-interactive, #ececec); color: var(--color-base, inherit); vertical-align: middle; text-align: center;" class="table-na">—
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r1126788409"><div class="plainlist">
<ul><li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">int</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">signed</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">signed int</span></li></ul>
</div>
</td>
<td>Basic signed integer type. Capable of containing at least the <span class="texhtml texhtml-big" style="font-size:100%;">[<span class="nowrap"><span data-sort-value="2995672330000000000♠"></span>−32<span style="margin-left:.25em;">767</span></span>, <span class="nowrap"><span data-sort-value="7004327670000000000♠"></span>+32<span style="margin-left:.25em;">767</span></span>]</span> range.<sup id="cite_ref-c99sizes_5-4" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99sizes-5"><span class="cite-bracket">[</span>4<span class="cite-bracket">]</span></a></sup><sup id="cite_ref-restr_8-2" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-restr-8"><span class="cite-bracket">[</span>b<span class="cite-bracket">]</span></a></sup></td>
<td>≥16</td>
<td><code>%i</code> or <code>%d</code></td>
<td>[<link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">INT_MIN</span>, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">INT_MAX</span>]</td>
<td style="background: #EEE; color:black; vertical-align: middle; text-align: center;" class="table-cast">none<sup id="cite_ref-c99intconst_13-0" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99intconst-13"><span class="cite-bracket">[</span>9<span class="cite-bracket">]</span></a></sup>
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r1126788409"><div class="plainlist">
<ul><li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">unsigned</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">unsigned int</span></li></ul>
</div>
</td>
<td>Basic unsigned integer type. Contains at least the <span class="texhtml texhtml-big" style="font-size:100%;">[<span class="nowrap"><span data-sort-value="5000000000000000000♠"></span>0</span>, <span class="nowrap"><span data-sort-value="7004655350000000000♠"></span>65<span style="margin-left:.25em;">535</span></span>]</span> range.<sup id="cite_ref-c99sizes_5-5" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99sizes-5"><span class="cite-bracket">[</span>4<span class="cite-bracket">]</span></a></sup></td>
<td>≥16</td>
<td><code>%u</code></td>
<td>[0, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">UINT_MAX</span>]</td>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">u</span> or <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">U</span><sup id="cite_ref-c99intconst_13-1" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99intconst-13"><span class="cite-bracket">[</span>9<span class="cite-bracket">]</span></a></sup>
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r1126788409"><div class="plainlist">
<ul><li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">long</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">long int</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">signed long</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">signed long int</span></li></ul>
</div>
</td>
<td><i>Long</i> signed integer type. Capable of containing at least the <span class="texhtml texhtml-big" style="font-size:100%;">[<span class="nowrap"><span data-sort-value="2990785251635300000♠"></span>−2<span style="margin-left:.25em;">147</span><span style="margin-left:.25em;">483</span><span style="margin-left:.25em;">647</span></span>, <span class="nowrap"><span data-sort-value="7009214748364700000♠"></span>+2<span style="margin-left:.25em;">147</span><span style="margin-left:.25em;">483</span><span style="margin-left:.25em;">647</span></span>]</span> range.<sup id="cite_ref-c99sizes_5-6" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99sizes-5"><span class="cite-bracket">[</span>4<span class="cite-bracket">]</span></a></sup><sup id="cite_ref-restr_8-3" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-restr-8"><span class="cite-bracket">[</span>b<span class="cite-bracket">]</span></a></sup></td>
<td>≥32</td>
<td><code>%li</code> or <code>%ld</code></td>
<td>[<link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">LONG_MIN</span>, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">LONG_MAX</span>]</td>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">l</span> or <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">L</span><sup id="cite_ref-c99intconst_13-2" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99intconst-13"><span class="cite-bracket">[</span>9<span class="cite-bracket">]</span></a></sup>
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r1126788409"><div class="plainlist">
<ul><li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">unsigned long</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">unsigned long int</span></li></ul>
</div>
</td>
<td><i>Long</i> unsigned integer type. Capable of containing at least the <span class="texhtml texhtml-big" style="font-size:100%;">[<span class="nowrap"><span data-sort-value="5000000000000000000♠"></span>0</span>, <span class="nowrap"><span data-sort-value="7009429496729500000♠"></span>4<span style="margin-left:.25em;">294</span><span style="margin-left:.25em;">967</span><span style="margin-left:.25em;">295</span></span>]</span> range.<sup id="cite_ref-c99sizes_5-7" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99sizes-5"><span class="cite-bracket">[</span>4<span class="cite-bracket">]</span></a></sup></td>
<td>≥32</td>
<td><code>%lu</code></td>
<td>[0, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">ULONG_MAX</span>]</td>
<td>both <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">u</span> or <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">U</span> and <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">l</span> or <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">L</span><sup id="cite_ref-c99intconst_13-3" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99intconst-13"><span class="cite-bracket">[</span>9<span class="cite-bracket">]</span></a></sup>
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r1126788409"><div class="plainlist">
<ul><li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">long long</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">long long int</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">signed long long</span></li>
<li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">signed long long int</span></li></ul>
</div>
</td>
<td><i>Long long</i> signed integer type. Capable of containing at least the <span class="texhtml texhtml-big" style="font-size:100%;">[<span class="nowrap"><span data-sort-value="2981077662796314522♠"></span>−9<span style="margin-left:.25em;">223</span><span style="margin-left:.25em;">372</span><span style="margin-left:.25em;">036</span><span style="margin-left:.25em;">854</span><span style="margin-left:.25em;">775</span><span style="margin-left:.25em;">807</span></span>, <span class="nowrap"><span data-sort-value="7018922337203685477♠"></span>+9<span style="margin-left:.25em;">223</span><span style="margin-left:.25em;">372</span><span style="margin-left:.25em;">036</span><span style="margin-left:.25em;">854</span><span style="margin-left:.25em;">775</span><span style="margin-left:.25em;">807</span></span>]</span> range.<sup id="cite_ref-c99sizes_5-8" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99sizes-5"><span class="cite-bracket">[</span>4<span class="cite-bracket">]</span></a></sup><sup id="cite_ref-restr_8-4" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-restr-8"><span class="cite-bracket">[</span>b<span class="cite-bracket">]</span></a></sup> Specified since the <a href="https://en.wikipedia.org/wiki/C_data_types/wiki/C99" title="C99">C99</a> version of the standard.</td>
<td>≥64</td>
<td><code>%lli</code> or <code>%lld</code></td>
<td>[<link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">LLONG_MIN</span>, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">LLONG_MAX</span>]</td>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">ll</span> or <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">LL</span><sup id="cite_ref-c99intconst_13-4" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99intconst-13"><span class="cite-bracket">[</span>9<span class="cite-bracket">]</span></a></sup>
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r1126788409"><div class="plainlist">
<ul><li><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">unsigned long long</span></li>
<li><span class="nowrap"><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">unsigned long long int</span></span></li></ul>
</div>
</td>
<td><i>Long long</i> unsigned integer type. Contains at least the <span class="texhtml texhtml-big" style="font-size:100%;">[<span class="nowrap"><span data-sort-value="5000000000000000000♠"></span>0</span>, <span class="nowrap"><span data-sort-value="7019184467440737095♠"></span>18<span style="margin-left:.25em;">446</span><span style="margin-left:.25em;">744</span><span style="margin-left:.25em;">073</span><span style="margin-left:.25em;">709</span><span style="margin-left:.25em;">551</span><span style="margin-left:.25em;">615</span></span>]</span> range.<sup id="cite_ref-c99sizes_5-9" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99sizes-5"><span class="cite-bracket">[</span>4<span class="cite-bracket">]</span></a></sup> Specified since the <a href="https://en.wikipedia.org/wiki/C99" title="C99">C99</a> version of the standard.</td>
<td>≥64</td>
<td><code>%llu</code></td>
<td>[0, <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">ULLONG_MAX</span>]</td>
<td>both <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">u</span> or <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">U</span> and <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">ll</span> or <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">LL</span><sup id="cite_ref-c99intconst_13-5" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-c99intconst-13"><span class="cite-bracket">[</span>9<span class="cite-bracket">]</span></a></sup>
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">float</span></td>
<td>Real floating-point type, usually referred to as a single-precision floating-point type. Actual properties unspecified (except minimum limits); however, on most systems, this is the <a href="/wiki/Single-precision_floating-point_format" title="Single-precision floating-point format">IEEE 754 single-precision binary floating-point format</a> (32 bits). This format is required by the optional Annex F "IEC 60559 floating-point arithmetic".
</td>
<td>
</td>
<td>Converting from text:<sup id="cite_ref-14" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-14"><span class="cite-bracket">[</span>e<span class="cite-bracket">]</span></a></sup><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r1126788409"><div class="plainlist"><ul><li><code>%f</code> <code>%F</code></li><li><code>%g</code> <code>%G</code></li><li><code>%e</code> <code>%E</code></li><li><code>%a</code> <code>%A</code></li></ul></div></td>
<td></td>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">f</span> or <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">F</span>
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">double</span></td>
<td>Real floating-point type, usually referred to as a double-precision floating-point type. Actual properties unspecified (except minimum limits); however, on most systems, this is the <a href="https://en.wikipedia.org/wiki/Double-precision_floating-point_format" title="Double-precision floating-point format">IEEE 754 double-precision binary floating-point format</a> (64 bits). This format is required by the optional Annex F "IEC 60559 floating-point arithmetic".
</td>
<td>
</td>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r1126788409"><div class="plainlist"><ul><li><code>%lf</code> <code>%lF</code></li><li><code>%lg</code> <code>%lG</code></li><li><code>%le</code> <code>%lE</code></li><li><code>%la</code> <code>%lA</code><sup id="cite_ref-uplowcase_15-0" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-uplowcase-15"><span class="cite-bracket">[</span>f<span class="cite-bracket">]</span></a></sup></li></ul></div></td>
<td></td>
<td>none
</td></tr>
<tr>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">long double</span></td>
<td>Real floating-point type, usually mapped to an <a href="https://en.wikipedia.org/wiki/C_data_types/wiki/Extended_precision" title="Extended precision">extended precision</a> floating-point number format. Actual properties unspecified. It can be either <a href="https://en.wikipedia.org/wiki/Extended_precision#x86_extended-precision_format" title="Extended precision">x86 extended-precision floating-point format</a> (80 bits, but typically 96 bits or 128 bits in memory with <a href="https://en.wikipedia.org/wiki/Data_structure_alignment" title="Data structure alignment">padding bytes</a>), the non-IEEE "<a href="https://en.wikipedia.org/wiki/Double-double_arithmetic" class="mw-redirect" title="Double-double arithmetic">double-double</a>" (128 bits), <a href="https://en.wikipedia.org/wiki/IEEE_754_quadruple-precision_floating-point_format" class="mw-redirect" title="IEEE 754 quadruple-precision floating-point format">IEEE 754 quadruple-precision floating-point format</a> (128 bits), or the same as double. See <a href="https://en.wikipedia.org/wiki/Long_double" title="Long double">the article on long double</a> for details.
</td>
<td>
</td>
<td><code>%Lf</code> <code>%LF</code><br><code>%Lg</code> <code>%LG</code><br><code>%Le</code> <code>%LE</code><br><code>%La</code> <code>%LA</code><sup id="cite_ref-uplowcase_15-1" class="reference"><a href="https://en.wikipedia.org/wiki/C_data_types#cite_note-uplowcase-15"><span class="cite-bracket">[</span>f<span class="cite-bracket">]</span></a></sup></td>
<td></td>
<td><link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">l</span> or <link rel="mw-deduplicated-inline-style" href="mw-data:TemplateStyles:r886049734"><span class="monospaced">L</span>
</td></tr></tbody>
</table>

# C언어에서 `int main(int argc, char* argc[])` 의미[|🔝|](#link)
- 리눅스에서 test해야 원하는 결과가 나온다.
  - https://almond0115.tistory.com/entry/main%ED%95%A8%EC%88%98-%EB%A7%A4%EA%B0%9C%EB%B3%80%EC%88%98-argc%EC%99%80-argv

> `int argc` : 메인 함수에 전달되는 정보의 개수(argument count)

> `char* argv[]` : 메인 함수에 전달되는 실질적인 정보로, 문자열의 배열을 의미
> 프로그램을 실행할 때 지정해 준 인자의 문자열들이 실제로 저장되는 배열
> 인덱스가 0인 문자열은 프로그램 실행경로로 항상 고정되어 있다.(argument vector)
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    printf("Hello world C lang ");

    int i;
    
    for (i=0; i < argc; i++) {
        printf("%s", argv[i]);
    }
    exit(0);
}
```

- result(LinuxOS)

```bash
./main I AM JONGHYUN

argv[0] : ./main
argv[1] : I
argv[2] : AM
argv[3] : JONGHYUN
```

- result(macOS)
```bash
 ./target/a01_c_test_argc /hello good
Hello world C lang ./target/a01_c_test_argc/hellogood
```
