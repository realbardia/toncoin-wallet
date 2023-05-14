#! /bin/sh

# Set the home if not already set.
if [ "${TONIUM_SRC_PATH}" = "" ]; then
    TONIUM_SRC_PATH="`echo $0 | grep ^/`"
    if [ "$TONIUM_SRC_PATH" = "" ]; then
    TONIUM_SRC_PATH="$PWD"/"$0"
    fi
    cd `dirname $TONIUM_SRC_PATH`
    TONIUM_SRC_PATH=$PWD
    cd -
fi

cd $TONIUM_SRC_PATH
for TRANSLATION in ./translations/*.ts
do
    lupdate `find -name '*.cpp' -type f` \
            `find -name '*.qml' -type f` \
            `find -name '*.h' -type f` \
            `find -name '*.ui' -type f` \
            -ts "$TRANSLATION"
            
    sed -i 's/ type="vanished"//g' "$TRANSLATION"
done

