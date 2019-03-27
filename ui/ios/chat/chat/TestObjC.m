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
}

@end
