export LD_LIBRARY_PATH := ../src/steppinrazor/parser:../src/steppinrazor


all: run

run: TestInts.class TestLongs.class TestFloats.class TestDoubles.class TestConversions.class TestComparisons.class TestGotoW.class TestSwitch.class TestLDC.class TestInts.testspec TestLongs.testspec TestFloats.testspec TestDoubles.testspec TestConversions.testspec TestComparisons.testspec TestGotoW.testspec TestSwitch.testspec TestLDC.testspec
	../src/test_runner TestInts
	../src/test_runner TestLongs
	../src/test_runner TestFloats
	../src/test_runner TestDoubles
	../src/test_runner TestConversions
	../src/test_runner TestComparisons
	../src/test_runner TestGotoW
	../src/test_runner TestSwitch
	../src/test_runner TestLDC
	@echo -e "\n-----------------------------\nAll tests successful!\n-----------------------------"
