all: testdoubles_-init- testfloats_-init- testints_-init- testlongs_-init- teststack_-init-

testdoubles_-init-: TestDoubles.class
	catmother-bytecodeexporter $<
testfloats_-init-: TestFloats.class
	catmother-bytecodeexporter $<
testints_-init-: TestInts.class
	catmother-bytecodeexporter $<
testlongs_-init-: TestLongs.class
	catmother-bytecodeexporter $<
teststack_-init-: TestStack.class
	catmother-bytecodeexporter $<	

%.class: %.java
	javac $<
