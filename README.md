# Haffmans-Algorithm
Huffman's Algorithm implementation on C++. Uses priority_queue for storing nodes. Involves bitwise operations for compressing and decompressing files. At this point, works fine with some types of files

Contents of HeaderFile:
<div class="textblock"><code>#include &lt;string&gt;</code><br />
<code>#include &lt;unordered_map&gt;</code><br />
</div>
<table class="memberdecls">
<tr class="heading"><td colspan="2"><h2 class="groupheader"><a id="nested-classes" name="nested-classes"></a>
Classes</h2></td></tr>
<tr class="memitem:"><td class="memItemLeft" align="right" valign="top">struct &#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_node.html">Node</a></td></tr>
<tr class="memdesc:"><td class="mdescLeft">&#160;</td><td class="mdescRight">Структура узла дерева Хаффмана Узел дерева Хаффмана содержит символ, частоту его появления, а также указатель на сопряжённые ветви.  <a href="struct_node.html#details">More...</a><br /></td></tr>
<tr class="separator:"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:"><td class="memItemLeft" align="right" valign="top">struct &#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="structcomp.html">comp</a></td></tr>
<tr class="memdesc:"><td class="mdescLeft">&#160;</td><td class="mdescRight">Структура, описывающая операцию сравнения элементов для приоритетной очереди  <a href="structcomp.html#details">More...</a><br /></td></tr>
<tr class="separator:"><td class="memSeparator" colspan="2">&#160;</td></tr>
</table><table class="memberdecls">
<tr class="heading"><td colspan="2"><h2 class="groupheader"><a id="func-members" name="func-members"></a>
Functions</h2></td></tr>
<tr class="memitem:ga0d79cc4dec1d211ba416271365bb1ea0"><td class="memItemLeft" align="right" valign="top">int&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__main__functions.html#ga0d79cc4dec1d211ba416271365bb1ea0">check_task</a> (char *argv[])</td></tr>
<tr class="memdesc:ga0d79cc4dec1d211ba416271365bb1ea0"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для определения задачи (сжатие / разархивация)  <a href="group__main__functions.html#ga0d79cc4dec1d211ba416271365bb1ea0">More...</a><br /></td></tr>
<tr class="separator:ga0d79cc4dec1d211ba416271365bb1ea0"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:gaaa4e3edd41f9b13a051b7cb691e96e00"><td class="memItemLeft" align="right" valign="top">std::string&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__fstream__functions.html#gaaa4e3edd41f9b13a051b7cb691e96e00">gen_en_filename</a> (std::string original)</td></tr>
<tr class="memdesc:gaaa4e3edd41f9b13a051b7cb691e96e00"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для генерации имени сжатого файла  <a href="group__fstream__functions.html#gaaa4e3edd41f9b13a051b7cb691e96e00">More...</a><br /></td></tr>
<tr class="separator:gaaa4e3edd41f9b13a051b7cb691e96e00"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:ga0aacc725ecb0dba38ce5fe6b1724284c"><td class="memItemLeft" align="right" valign="top">std::string&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__fstream__functions.html#ga0aacc725ecb0dba38ce5fe6b1724284c">gen_de_filename</a> (std::string original)</td></tr>
<tr class="memdesc:ga0aacc725ecb0dba38ce5fe6b1724284c"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для генерации имени разархивированного файла  <a href="group__fstream__functions.html#ga0aacc725ecb0dba38ce5fe6b1724284c">More...</a><br /></td></tr>
<tr class="separator:ga0aacc725ecb0dba38ce5fe6b1724284c"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:gaf8fb5820afd35764bb24e93ad264511a"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__fstream__functions.html#gaf8fb5820afd35764bb24e93ad264511a">insert_zeros_counter</a> (std::ofstream &amp;outfile, int bits)</td></tr>
<tr class="memdesc:gaf8fb5820afd35764bb24e93ad264511a"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для записи кол-ва дополнительных нулей в бинарный файл  <a href="group__fstream__functions.html#gaf8fb5820afd35764bb24e93ad264511a">More...</a><br /></td></tr>
<tr class="separator:gaf8fb5820afd35764bb24e93ad264511a"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:gae02d5d4d8c39f3e99d3e04a718956fd8"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__fstream__functions.html#gae02d5d4d8c39f3e99d3e04a718956fd8">writeBinaryString</a> (std::ofstream &amp;outfile, std::string &amp;str)</td></tr>
<tr class="memdesc:gae02d5d4d8c39f3e99d3e04a718956fd8"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для записи битовой строки в бинарный файл  <a href="group__fstream__functions.html#gae02d5d4d8c39f3e99d3e04a718956fd8">More...</a><br /></td></tr>
<tr class="separator:gae02d5d4d8c39f3e99d3e04a718956fd8"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:gac1eef9aec8e4bc048f6100e481f99ad3"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__fstream__functions.html#gac1eef9aec8e4bc048f6100e481f99ad3">writeBinaryTree</a> (<a class="el" href="struct_node.html">Node</a> *node, std::string &amp;result)</td></tr>
<tr class="memdesc:gac1eef9aec8e4bc048f6100e481f99ad3"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для генерации строковой репрезентации бинарного дерева Хаффмана  <a href="group__fstream__functions.html#gac1eef9aec8e4bc048f6100e481f99ad3">More...</a><br /></td></tr>
<tr class="separator:gac1eef9aec8e4bc048f6100e481f99ad3"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:gac0d3bfdb204e30de6b6833e1415d39c8"><td class="memItemLeft" align="right" valign="top"><a class="el" href="struct_node.html">Node</a> *&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__fstream__functions.html#gac0d3bfdb204e30de6b6833e1415d39c8">readBinaryTree</a> (std::string &amp;str, int &amp;index)</td></tr>
<tr class="memdesc:gac0d3bfdb204e30de6b6833e1415d39c8"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для генерации бинарного дерева Хаффмана на основе его строковой репрезентации  <a href="group__fstream__functions.html#gac0d3bfdb204e30de6b6833e1415d39c8">More...</a><br /></td></tr>
<tr class="separator:gac0d3bfdb204e30de6b6833e1415d39c8"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:gac4de3d978261162c370c09a057609be1"><td class="memItemLeft" align="right" valign="top">int&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__fstream__functions.html#gac4de3d978261162c370c09a057609be1">parse_file</a> (std::string &amp;name, std::string &amp;text)</td></tr>
<tr class="memdesc:gac4de3d978261162c370c09a057609be1"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для считывания исходного текста  <a href="group__fstream__functions.html#gac4de3d978261162c370c09a057609be1">More...</a><br /></td></tr>
<tr class="separator:gac4de3d978261162c370c09a057609be1"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:ga29932639a36ec78375e301ffe1e3e9fe"><td class="memItemLeft" align="right" valign="top">int&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__fstream__functions.html#ga29932639a36ec78375e301ffe1e3e9fe">parse_tree</a> (std::ifstream &amp;infile, std::string &amp;text)</td></tr>
<tr class="memdesc:ga29932639a36ec78375e301ffe1e3e9fe"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для считывания строковой репрезентации дерева из бинарного файла  <a href="group__fstream__functions.html#ga29932639a36ec78375e301ffe1e3e9fe">More...</a><br /></td></tr>
<tr class="separator:ga29932639a36ec78375e301ffe1e3e9fe"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:ga93fe831c5c78c54f5ae8c24f62750162"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__fstream__functions.html#ga93fe831c5c78c54f5ae8c24f62750162">parse_binary_text</a> (std::ifstream &amp;infile, std::string &amp;text, int tree_size, int zeros)</td></tr>
<tr class="memdesc:ga93fe831c5c78c54f5ae8c24f62750162"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для считывания байтов текста из бинарного файла  <a href="group__fstream__functions.html#ga93fe831c5c78c54f5ae8c24f62750162">More...</a><br /></td></tr>
<tr class="separator:ga93fe831c5c78c54f5ae8c24f62750162"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:ga31e960a9e4edcec22363f912b7f99e90"><td class="memItemLeft" align="right" valign="top"><a class="el" href="struct_node.html">Node</a> *&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__encode__functions.html#ga31e960a9e4edcec22363f912b7f99e90">addNode</a> (char ch, int freq, <a class="el" href="struct_node.html">Node</a> *left, <a class="el" href="struct_node.html">Node</a> *right)</td></tr>
<tr class="memdesc:ga31e960a9e4edcec22363f912b7f99e90"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для создания узла  <a href="group__encode__functions.html#ga31e960a9e4edcec22363f912b7f99e90">More...</a><br /></td></tr>
<tr class="separator:ga31e960a9e4edcec22363f912b7f99e90"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:ga9310a7f607eff6564060277d06946ff5"><td class="memItemLeft" align="right" valign="top">int&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__encode__functions.html#ga9310a7f607eff6564060277d06946ff5">pack</a> (std::string &amp;name)</td></tr>
<tr class="memdesc:ga9310a7f607eff6564060277d06946ff5"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для архивации текста  <a href="group__encode__functions.html#ga9310a7f607eff6564060277d06946ff5">More...</a><br /></td></tr>
<tr class="separator:ga9310a7f607eff6564060277d06946ff5"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:ga7f9f4fd71711f672999ed64c179de162"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__encode__functions.html#ga7f9f4fd71711f672999ed64c179de162">encode</a> (<a class="el" href="struct_node.html">Node</a> *root, std::string str, std::unordered_map&lt; char, std::string &gt; &amp;huffmanCode)</td></tr>
<tr class="memdesc:ga7f9f4fd71711f672999ed64c179de162"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для определения кодов символов  <a href="group__encode__functions.html#ga7f9f4fd71711f672999ed64c179de162">More...</a><br /></td></tr>
<tr class="separator:ga7f9f4fd71711f672999ed64c179de162"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:ga66ae38d7f6b66cd05fb0d9d13b620786"><td class="memItemLeft" align="right" valign="top">std::unordered_map&lt; char, int &gt;&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__encode__functions.html#ga66ae38d7f6b66cd05fb0d9d13b620786">find_frequency</a> (std::string &amp;text)</td></tr>
<tr class="memdesc:ga66ae38d7f6b66cd05fb0d9d13b620786"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для определения частоты употребления символов в исходном тексте  <a href="group__encode__functions.html#ga66ae38d7f6b66cd05fb0d9d13b620786">More...</a><br /></td></tr>
<tr class="separator:ga66ae38d7f6b66cd05fb0d9d13b620786"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:gaf203085723d85267826651a8f463f994"><td class="memItemLeft" align="right" valign="top"><a class="el" href="struct_node.html">Node</a> *&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__encode__functions.html#gaf203085723d85267826651a8f463f994">build_tree</a> (std::unordered_map&lt; char, int &gt; freq)</td></tr>
<tr class="memdesc:gaf203085723d85267826651a8f463f994"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для генерации дерева Хаффмана  <a href="group__encode__functions.html#gaf203085723d85267826651a8f463f994">More...</a><br /></td></tr>
<tr class="separator:gaf203085723d85267826651a8f463f994"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:ga683c8874c686b509e9ae359f27ff0da4"><td class="memItemLeft" align="right" valign="top">int&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__decode__functions.html#ga683c8874c686b509e9ae359f27ff0da4">unpack</a> (std::string &amp;name)</td></tr>
<tr class="memdesc:ga683c8874c686b509e9ae359f27ff0da4"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для разархивации текста  <a href="group__decode__functions.html#ga683c8874c686b509e9ae359f27ff0da4">More...</a><br /></td></tr>
<tr class="separator:ga683c8874c686b509e9ae359f27ff0da4"><td class="memSeparator" colspan="2">&#160;</td></tr>
<tr class="memitem:gac6c9fb12155eaef792b9f33f7ddcabe1"><td class="memItemLeft" align="right" valign="top">void&#160;</td><td class="memItemRight" valign="bottom"><a class="el" href="group__decode__functions.html#gac6c9fb12155eaef792b9f33f7ddcabe1">decode</a> (<a class="el" href="struct_node.html">Node</a> *root, std::string &amp;str, std::ofstream &amp;outfile)</td></tr>
<tr class="memdesc:gac6c9fb12155eaef792b9f33f7ddcabe1"><td class="mdescLeft">&#160;</td><td class="mdescRight">Функция для декодирования битовой последовательности  <a href="group__decode__functions.html#gac6c9fb12155eaef792b9f33f7ddcabe1">More...</a><br /></td></tr>
<tr class="separator:gac6c9fb12155eaef792b9f33f7ddcabe1"><td class="memSeparator" colspan="2">&#160;</td></tr>
</table>

</div></div><!-- contents -->
<!-- start footer part -->
</body>
</html>
