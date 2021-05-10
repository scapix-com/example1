//
//  TestObjC.m
//  chat
//

#import "TestObjC.h"

#import "chat/bridge/Contact.h"
#import "chat/bridge/Session.h"
#import "chat/bridge/Model.h"

@implementation TestObjC

-(void) sample
{
    Contact* c = [Contact new];
    
    [c name:@"hello"];
    NSString* n = [c name];
    [c name:n];
    
    Session* s = [Session new];
    
    [s addContact:c];
    [s sendMessage:@"aaa"];
    [s sendMessage2:@"bbb" count:5];

	Model* m = [Model new];

	Struct1 s1;
	s1.a = 77;
	s1.b = @"from objc";
	s1.buffer = @[@33, @44];

	Struct2 s2;
	s2.strings = @[@"string1", @"string2"];
	s2.callback = ^NSString*(NSString* s)
	{
		return [NSString stringWithFormat:@"%@ from objc callback", s];
	};
	s2.f1 = s1;

	Struct1 s11 __unused = [m testStruct:s2];
	m = nil;
}

@end
