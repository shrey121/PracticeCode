echo Enter file

read file

sed -e 's/linux//g' $file | cat >asdf.txt

cp asdf.txt $file
rm asdf.txt

cat $file
