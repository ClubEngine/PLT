#!/bin/bash

# params
# output dir
gameplay="gameplay"
# template dir
data="data"

echo "Generate a directory with source of classes model, view and controller"

echo "Enter name of the state: (e.g Game)"
echo "will generate GameState, GameView, ..."
echo "The result will be in a directory under the gameplay directory"
read statename

function tolowcase() {
	echo $1 | tr '[:upper:]' '[:lower:]'	
}
function toupcase() {
	echo $1 | tr '[:lower:]' '[:upper:]'	
}
function tocapital() {
	echo $(toupcase $(echo $1 | cut -c 1))$(echo $1 | cut -c 2-)
}
function mmkdir() {
	mkdir -p $@
}

cd "$(dirname "$0")"

statedir=$gameplay/$(tolowcase $statename)

mmkdir $gameplay
mmkdir $statedir
mmkdir $statedir/models
mmkdir $statedir/views
mmkdir $statedir/controllers

classState="${statename}State"
classModel="${statename}Model"
classView="${statename}View"
classController="${statename}Controller"

headerGuard_state=$(toupcase $classState)_HPP
headerGuard_m=$(toupcase $classModel)_HPP
headerGuard_v=$(toupcase $classView)_HPP
headerGuard_c=$(toupcase $classController)_HPP

# fct to compile a template
# $1 src
# $2 dst
function template_run {
	(cat $1 |
	sed "s/<<<HS>>>/$headerGuard_state/g" |
	sed "s/<<<HM>>>/$headerGuard_m/g" |
	sed "s/<<<HV>>>/$headerGuard_v/g" |
	sed "s/<<<HC>>>/$headerGuard_c/g" |

	sed "s/<<<CS>>>/$classState/g" |
	sed "s/<<<CM>>>/$classModel/g" |
	sed "s/<<<CV>>>/$classView/g" |
	sed "s/<<<CC>>>/$classController/g"

	) > $2
}



# for each template, compile it
for ext in cpp hpp ; do
	template_run $data/state.$ext $statedir/${statename}State.$ext
	for component in model view controller ; do
		compcap=$(tocapital $component)
		template_run $data/$component.$ext $statedir/${component}s/${statename}${compcap}.$ext
	done
done
