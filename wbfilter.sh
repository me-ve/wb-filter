if [ "$#" -eq 2 ] ;
then
    SAVE_COPY=0
    FILE_IN=$1
    FILE_OUT=$2
elif [ "$#" -eq 1 ] ;
then
    SAVE_COPY=1
    FILE_IN=$1
    FILE_OUT=$1
else
    exit 1
fi
pngtopam $FILE_IN >> .temp.ppm
convert .temp.ppm -compress none .temp.ppm
./wb .temp.ppm .temp.pgm
if [ $SAVE_COPY -eq 1 ]
then
    cp $FILE_OUT $FILE_OUT.old
    rm $FILE_OUT
fi
pamtopng .temp.pgm >> $FILE_OUT
rm .temp.*
exit 0
