#make fclean
#make push_swap
cd _visualizer/c
echo "<!> compiling json list generator"
gcc list_jsonifier.c -o list_jsonifier.exe
#./list_jsonifier.exe "unsorted_list" "$(cat ../unsorted_list.txt)" "0" > ../unsorted_list.json 
cd ../..
#echo "<!> running push_swap on generated list ..."
#./push_swap -jo $(cat _visualizer/unsorted_list.txt) > _visualizer/commands.txt
cd _visualizer/c
#cat ../commands.txt
echo "<!> building json from output ..."
./list_jsonifier.exe "lines" "$(cat ../../good_map)" "1" > ../lines.json
#./push_swap -j $(cat _visualizer/unsorted_list.txt) > _visualizer/all_in.json
cd ..
echo "<!> injecting json data to html hidden container"
sed '/<p id="lines">/ r lines.json' html/index_tpl.html > html/index.html

#open html/index.html
#xdg-open html/index.html
#awk 'FNR==NR{n=n ORS $0; next} /<integers>/{$0=$0 n} 1' output.txt index.html
