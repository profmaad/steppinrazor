all: testdoubles_-init- testfloats_-init- testints_-init- testlongs_-init- teststack_-init- testconversions_-init- testcomparisons_-init-

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
testconversions_-init-: TestConversions.class
	catmother-bytecodeexporter $<	
testcomparisons_-init-: TestComparisons.class
	catmother-bytecodeexporter $<	

%.class: %.java
	javac $<

clean:
	rm -f TestInts.class TestLongs.class TestFloats.class TestDoubles.class TestConversions.class TestComparisons.class
	rm -f test*

