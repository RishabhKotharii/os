echo "Enter the name of the directory:-"
read dname
mkdir $dname
cd $dname
echo "Enter the name of the sub directory:-"
read sname 
mkdir $sname
cd $sname
echo "Enter the name of the file "
read fname 
echo "Type the contents of the file"
cat > $fname
echo "Enter the name of the file to copy in"
read copyfilename
cp $fname $copyfilename
chmod 744 $fname $copyfilename
ls -l $fname $copyfilename