//
//  AMFActionMessage.h
//  SimpleHTTPServer
//
//  Created by Marc Bauer on 12.10.08.
//  Copyright 2008 nesiumdotcom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMF.h"
#import "AMFArchiver.h"
#import "AMFUnarchiver.h"


@interface AMFActionMessage : NSObject 
{
	AMFVersion m_version;
	NSMutableArray *m_headers;
	NSMutableArray *m_bodies;
}
@property (nonatomic, assign) AMFVersion version;
@property (nonatomic, retain) NSArray *headers;
@property (nonatomic, retain) NSArray *bodies;

- (id)initWithData:(NSData *)data;
- (NSData *)data;
- (void)addBodyWithTargetURI:(NSString *)targetURI responseURI:(NSString *)responseURI data:(id)data;
- (void)addHeaderWithName:(NSString *)name mustUnderstand:(BOOL)mustUnderstand data:(id)data;
@end


@interface AMFMessageHeader : NSObject 
{
	NSString *m_name;
	BOOL m_mustUnderstand;
	NSObject *m_data;
}
@property (nonatomic, retain) NSString *name;
@property (nonatomic, assign) BOOL mustUnderstand;
@property (nonatomic, retain) NSObject *data;
@end


@interface AMFMessageBody : NSObject 
{
	NSString *m_targetURI;
	NSString *m_responseURI;
	NSObject *m_data;
}
@property (nonatomic, retain) NSString *targetURI;
@property (nonatomic, retain) NSString *responseURI;
@property (nonatomic, retain) NSObject *data;
@end