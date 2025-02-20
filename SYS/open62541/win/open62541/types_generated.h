/* Generated from Opc.Ua.Types.bsd with script K:/sd/MCP/Devices/MCPJ/libs/open62541/src/tools/generate_datatypes.py
 * on host PLais-10 by user plais at 2020-02-12 11:37:17 */

#ifndef TYPES_GENERATED_H_
#define TYPES_GENERATED_H_

#ifdef UA_ENABLE_AMALGAMATION
#include "open62541.h"
#else
#include <open62541/types.h>

#endif

_UA_BEGIN_DECLS


/**
 * Every type is assigned an index in an array containing the type descriptions.
 * These descriptions are used during type handling (copying, deletion,
 * binary encoding, ...). */
#define UA_TYPES_COUNT 207
extern UA_EXPORT const UA_DataType UA_TYPES[UA_TYPES_COUNT];

/**
 * Boolean
 * ^^^^^^^
 */
#define UA_TYPES_BOOLEAN 0

/**
 * SByte
 * ^^^^^
 */
#define UA_TYPES_SBYTE 1

/**
 * Byte
 * ^^^^
 */
#define UA_TYPES_BYTE 2

/**
 * Int16
 * ^^^^^
 */
#define UA_TYPES_INT16 3

/**
 * UInt16
 * ^^^^^^
 */
#define UA_TYPES_UINT16 4

/**
 * Int32
 * ^^^^^
 */
#define UA_TYPES_INT32 5

/**
 * UInt32
 * ^^^^^^
 */
#define UA_TYPES_UINT32 6

/**
 * Int64
 * ^^^^^
 */
#define UA_TYPES_INT64 7

/**
 * UInt64
 * ^^^^^^
 */
#define UA_TYPES_UINT64 8

/**
 * Float
 * ^^^^^
 */
#define UA_TYPES_FLOAT 9

/**
 * Double
 * ^^^^^^
 */
#define UA_TYPES_DOUBLE 10

/**
 * String
 * ^^^^^^
 */
#define UA_TYPES_STRING 11

/**
 * DateTime
 * ^^^^^^^^
 */
#define UA_TYPES_DATETIME 12

/**
 * Guid
 * ^^^^
 */
#define UA_TYPES_GUID 13

/**
 * ByteString
 * ^^^^^^^^^^
 */
#define UA_TYPES_BYTESTRING 14

/**
 * XmlElement
 * ^^^^^^^^^^
 */
#define UA_TYPES_XMLELEMENT 15

/**
 * NodeId
 * ^^^^^^
 */
#define UA_TYPES_NODEID 16

/**
 * ExpandedNodeId
 * ^^^^^^^^^^^^^^
 */
#define UA_TYPES_EXPANDEDNODEID 17

/**
 * StatusCode
 * ^^^^^^^^^^
 */
#define UA_TYPES_STATUSCODE 18

/**
 * QualifiedName
 * ^^^^^^^^^^^^^
 */
#define UA_TYPES_QUALIFIEDNAME 19

/**
 * LocalizedText
 * ^^^^^^^^^^^^^
 */
#define UA_TYPES_LOCALIZEDTEXT 20

/**
 * ExtensionObject
 * ^^^^^^^^^^^^^^^
 */
#define UA_TYPES_EXTENSIONOBJECT 21

/**
 * DataValue
 * ^^^^^^^^^
 */
#define UA_TYPES_DATAVALUE 22

/**
 * Variant
 * ^^^^^^^
 */
#define UA_TYPES_VARIANT 23

/**
 * DiagnosticInfo
 * ^^^^^^^^^^^^^^
 */
#define UA_TYPES_DIAGNOSTICINFO 24

/**
 * NodeClass
 * ^^^^^^^^^
 * A mask specifying the class of the node. */
typedef enum {
    UA_NODECLASS_UNSPECIFIED = 0,
    UA_NODECLASS_OBJECT = 1,
    UA_NODECLASS_VARIABLE = 2,
    UA_NODECLASS_METHOD = 4,
    UA_NODECLASS_OBJECTTYPE = 8,
    UA_NODECLASS_VARIABLETYPE = 16,
    UA_NODECLASS_REFERENCETYPE = 32,
    UA_NODECLASS_DATATYPE = 64,
    UA_NODECLASS_VIEW = 128,
    __UA_NODECLASS_FORCE32BIT = 0x7fffffff
} UA_NodeClass;
UA_STATIC_ASSERT(sizeof(UA_NodeClass) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_NODECLASS 25

/**
 * Argument
 * ^^^^^^^^
 * An argument for a method. */
typedef struct {
    UA_String name;
    UA_NodeId dataType;
    UA_Int32 valueRank;
    size_t arrayDimensionsSize;
    UA_UInt32 *arrayDimensions;
    UA_LocalizedText description;
} UA_Argument;

#define UA_TYPES_ARGUMENT 26

/**
 * EnumValueType
 * ^^^^^^^^^^^^^
 * A mapping between a value of an enumerated type and a name and description. */
typedef struct {
    UA_Int64 value;
    UA_LocalizedText displayName;
    UA_LocalizedText description;
} UA_EnumValueType;

#define UA_TYPES_ENUMVALUETYPE 27

/**
 * Duration
 * ^^^^^^^^
 * A period of time measured in milliseconds. */
typedef UA_Double UA_Duration;

#define UA_TYPES_DURATION 28

/**
 * UtcTime
 * ^^^^^^^
 * A date/time value specified in Universal Coordinated Time (UTC). */
typedef UA_DateTime UA_UtcTime;

#define UA_TYPES_UTCTIME 29

/**
 * LocaleId
 * ^^^^^^^^
 * An identifier for a user locale. */
typedef UA_String UA_LocaleId;

#define UA_TYPES_LOCALEID 30

/**
 * TimeZoneDataType
 * ^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_Int16 offset;
    UA_Boolean daylightSavingInOffset;
} UA_TimeZoneDataType;

#define UA_TYPES_TIMEZONEDATATYPE 31

/**
 * ApplicationType
 * ^^^^^^^^^^^^^^^
 * The types of applications. */
typedef enum {
    UA_APPLICATIONTYPE_SERVER = 0,
    UA_APPLICATIONTYPE_CLIENT = 1,
    UA_APPLICATIONTYPE_CLIENTANDSERVER = 2,
    UA_APPLICATIONTYPE_DISCOVERYSERVER = 3,
    __UA_APPLICATIONTYPE_FORCE32BIT = 0x7fffffff
} UA_ApplicationType;
UA_STATIC_ASSERT(sizeof(UA_ApplicationType) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_APPLICATIONTYPE 32

/**
 * ApplicationDescription
 * ^^^^^^^^^^^^^^^^^^^^^^
 * Describes an application and how to find it. */
typedef struct {
    UA_String applicationUri;
    UA_String productUri;
    UA_LocalizedText applicationName;
    UA_ApplicationType applicationType;
    UA_String gatewayServerUri;
    UA_String discoveryProfileUri;
    size_t discoveryUrlsSize;
    UA_String *discoveryUrls;
} UA_ApplicationDescription;

#define UA_TYPES_APPLICATIONDESCRIPTION 33

/**
 * RequestHeader
 * ^^^^^^^^^^^^^
 * The header passed with every server request. */
typedef struct {
    UA_NodeId authenticationToken;
    UA_DateTime timestamp;
    UA_UInt32 requestHandle;
    UA_UInt32 returnDiagnostics;
    UA_String auditEntryId;
    UA_UInt32 timeoutHint;
    UA_ExtensionObject additionalHeader;
} UA_RequestHeader;

#define UA_TYPES_REQUESTHEADER 34

/**
 * ResponseHeader
 * ^^^^^^^^^^^^^^
 * The header passed with every server response. */
typedef struct {
    UA_DateTime timestamp;
    UA_UInt32 requestHandle;
    UA_StatusCode serviceResult;
    UA_DiagnosticInfo serviceDiagnostics;
    size_t stringTableSize;
    UA_String *stringTable;
    UA_ExtensionObject additionalHeader;
} UA_ResponseHeader;

#define UA_TYPES_RESPONSEHEADER 35

/**
 * ServiceFault
 * ^^^^^^^^^^^^
 * The response returned by all services when there is a service level error. */
typedef struct {
    UA_ResponseHeader responseHeader;
} UA_ServiceFault;

#define UA_TYPES_SERVICEFAULT 36

/**
 * FindServersRequest
 * ^^^^^^^^^^^^^^^^^^
 * Finds the servers known to the discovery server. */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_String endpointUrl;
    size_t localeIdsSize;
    UA_String *localeIds;
    size_t serverUrisSize;
    UA_String *serverUris;
} UA_FindServersRequest;

#define UA_TYPES_FINDSERVERSREQUEST 37

/**
 * FindServersResponse
 * ^^^^^^^^^^^^^^^^^^^
 * Finds the servers known to the discovery server. */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t serversSize;
    UA_ApplicationDescription *servers;
} UA_FindServersResponse;

#define UA_TYPES_FINDSERVERSRESPONSE 38

/**
 * ServerOnNetwork
 * ^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_UInt32 recordId;
    UA_String serverName;
    UA_String discoveryUrl;
    size_t serverCapabilitiesSize;
    UA_String *serverCapabilities;
} UA_ServerOnNetwork;

#define UA_TYPES_SERVERONNETWORK 39

/**
 * FindServersOnNetworkRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_UInt32 startingRecordId;
    UA_UInt32 maxRecordsToReturn;
    size_t serverCapabilityFilterSize;
    UA_String *serverCapabilityFilter;
} UA_FindServersOnNetworkRequest;

#define UA_TYPES_FINDSERVERSONNETWORKREQUEST 40

/**
 * FindServersOnNetworkResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    UA_DateTime lastCounterResetTime;
    size_t serversSize;
    UA_ServerOnNetwork *servers;
} UA_FindServersOnNetworkResponse;

#define UA_TYPES_FINDSERVERSONNETWORKRESPONSE 41

/**
 * MessageSecurityMode
 * ^^^^^^^^^^^^^^^^^^^
 * The type of security to use on a message. */
typedef enum {
    UA_MESSAGESECURITYMODE_INVALID = 0,
    UA_MESSAGESECURITYMODE_NONE = 1,
    UA_MESSAGESECURITYMODE_SIGN = 2,
    UA_MESSAGESECURITYMODE_SIGNANDENCRYPT = 3,
    __UA_MESSAGESECURITYMODE_FORCE32BIT = 0x7fffffff
} UA_MessageSecurityMode;
UA_STATIC_ASSERT(sizeof(UA_MessageSecurityMode) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_MESSAGESECURITYMODE 42

/**
 * UserTokenType
 * ^^^^^^^^^^^^^
 * The possible user token types. */
typedef enum {
    UA_USERTOKENTYPE_ANONYMOUS = 0,
    UA_USERTOKENTYPE_USERNAME = 1,
    UA_USERTOKENTYPE_CERTIFICATE = 2,
    UA_USERTOKENTYPE_ISSUEDTOKEN = 3,
    __UA_USERTOKENTYPE_FORCE32BIT = 0x7fffffff
} UA_UserTokenType;
UA_STATIC_ASSERT(sizeof(UA_UserTokenType) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_USERTOKENTYPE 43

/**
 * UserTokenPolicy
 * ^^^^^^^^^^^^^^^
 * Describes a user token that can be used with a server. */
typedef struct {
    UA_String policyId;
    UA_UserTokenType tokenType;
    UA_String issuedTokenType;
    UA_String issuerEndpointUrl;
    UA_String securityPolicyUri;
} UA_UserTokenPolicy;

#define UA_TYPES_USERTOKENPOLICY 44

/**
 * EndpointDescription
 * ^^^^^^^^^^^^^^^^^^^
 * The description of a endpoint that can be used to access a server. */
typedef struct {
    UA_String endpointUrl;
    UA_ApplicationDescription server;
    UA_ByteString serverCertificate;
    UA_MessageSecurityMode securityMode;
    UA_String securityPolicyUri;
    size_t userIdentityTokensSize;
    UA_UserTokenPolicy *userIdentityTokens;
    UA_String transportProfileUri;
    UA_Byte securityLevel;
} UA_EndpointDescription;

#define UA_TYPES_ENDPOINTDESCRIPTION 45

/**
 * GetEndpointsRequest
 * ^^^^^^^^^^^^^^^^^^^
 * Gets the endpoints used by the server. */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_String endpointUrl;
    size_t localeIdsSize;
    UA_String *localeIds;
    size_t profileUrisSize;
    UA_String *profileUris;
} UA_GetEndpointsRequest;

#define UA_TYPES_GETENDPOINTSREQUEST 46

/**
 * GetEndpointsResponse
 * ^^^^^^^^^^^^^^^^^^^^
 * Gets the endpoints used by the server. */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t endpointsSize;
    UA_EndpointDescription *endpoints;
} UA_GetEndpointsResponse;

#define UA_TYPES_GETENDPOINTSRESPONSE 47

/**
 * RegisteredServer
 * ^^^^^^^^^^^^^^^^
 * The information required to register a server with a discovery server. */
typedef struct {
    UA_String serverUri;
    UA_String productUri;
    size_t serverNamesSize;
    UA_LocalizedText *serverNames;
    UA_ApplicationType serverType;
    UA_String gatewayServerUri;
    size_t discoveryUrlsSize;
    UA_String *discoveryUrls;
    UA_String semaphoreFilePath;
    UA_Boolean isOnline;
} UA_RegisteredServer;

#define UA_TYPES_REGISTEREDSERVER 48

/**
 * RegisterServerRequest
 * ^^^^^^^^^^^^^^^^^^^^^
 * Registers a server with the discovery server. */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_RegisteredServer server;
} UA_RegisterServerRequest;

#define UA_TYPES_REGISTERSERVERREQUEST 49

/**
 * RegisterServerResponse
 * ^^^^^^^^^^^^^^^^^^^^^^
 * Registers a server with the discovery server. */
typedef struct {
    UA_ResponseHeader responseHeader;
} UA_RegisterServerResponse;

#define UA_TYPES_REGISTERSERVERRESPONSE 50

/**
 * DiscoveryConfiguration
 * ^^^^^^^^^^^^^^^^^^^^^^
 * A base type for discovery configuration information. */
typedef void * UA_DiscoveryConfiguration;

#define UA_TYPES_DISCOVERYCONFIGURATION 51

/**
 * MdnsDiscoveryConfiguration
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^
 * The discovery information needed for mDNS registration. */
typedef struct {
    UA_String mdnsServerName;
    size_t serverCapabilitiesSize;
    UA_String *serverCapabilities;
} UA_MdnsDiscoveryConfiguration;

#define UA_TYPES_MDNSDISCOVERYCONFIGURATION 52

/**
 * RegisterServer2Request
 * ^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_RegisteredServer server;
    size_t discoveryConfigurationSize;
    UA_ExtensionObject *discoveryConfiguration;
} UA_RegisterServer2Request;

#define UA_TYPES_REGISTERSERVER2REQUEST 53

/**
 * RegisterServer2Response
 * ^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t configurationResultsSize;
    UA_StatusCode *configurationResults;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_RegisterServer2Response;

#define UA_TYPES_REGISTERSERVER2RESPONSE 54

/**
 * SecurityTokenRequestType
 * ^^^^^^^^^^^^^^^^^^^^^^^^
 * Indicates whether a token if being created or renewed. */
typedef enum {
    UA_SECURITYTOKENREQUESTTYPE_ISSUE = 0,
    UA_SECURITYTOKENREQUESTTYPE_RENEW = 1,
    __UA_SECURITYTOKENREQUESTTYPE_FORCE32BIT = 0x7fffffff
} UA_SecurityTokenRequestType;
UA_STATIC_ASSERT(sizeof(UA_SecurityTokenRequestType) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_SECURITYTOKENREQUESTTYPE 55

/**
 * ChannelSecurityToken
 * ^^^^^^^^^^^^^^^^^^^^
 * The token that identifies a set of keys for an active secure channel. */
typedef struct {
    UA_UInt32 channelId;
    UA_UInt32 tokenId;
    UA_DateTime createdAt;
    UA_UInt32 revisedLifetime;
} UA_ChannelSecurityToken;

#define UA_TYPES_CHANNELSECURITYTOKEN 56

/**
 * OpenSecureChannelRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^
 * Creates a secure channel with a server. */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_UInt32 clientProtocolVersion;
    UA_SecurityTokenRequestType requestType;
    UA_MessageSecurityMode securityMode;
    UA_ByteString clientNonce;
    UA_UInt32 requestedLifetime;
} UA_OpenSecureChannelRequest;

#define UA_TYPES_OPENSECURECHANNELREQUEST 57

/**
 * OpenSecureChannelResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 * Creates a secure channel with a server. */
typedef struct {
    UA_ResponseHeader responseHeader;
    UA_UInt32 serverProtocolVersion;
    UA_ChannelSecurityToken securityToken;
    UA_ByteString serverNonce;
} UA_OpenSecureChannelResponse;

#define UA_TYPES_OPENSECURECHANNELRESPONSE 58

/**
 * CloseSecureChannelRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 * Closes a secure channel. */
typedef struct {
    UA_RequestHeader requestHeader;
} UA_CloseSecureChannelRequest;

#define UA_TYPES_CLOSESECURECHANNELREQUEST 59

/**
 * CloseSecureChannelResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Closes a secure channel. */
typedef struct {
    UA_ResponseHeader responseHeader;
} UA_CloseSecureChannelResponse;

#define UA_TYPES_CLOSESECURECHANNELRESPONSE 60

/**
 * SignedSoftwareCertificate
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 * A software certificate with a digital signature. */
typedef struct {
    UA_ByteString certificateData;
    UA_ByteString signature;
} UA_SignedSoftwareCertificate;

#define UA_TYPES_SIGNEDSOFTWARECERTIFICATE 61

/**
 * SignatureData
 * ^^^^^^^^^^^^^
 * A digital signature. */
typedef struct {
    UA_String algorithm;
    UA_ByteString signature;
} UA_SignatureData;

#define UA_TYPES_SIGNATUREDATA 62

/**
 * CreateSessionRequest
 * ^^^^^^^^^^^^^^^^^^^^
 * Creates a new session with the server. */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_ApplicationDescription clientDescription;
    UA_String serverUri;
    UA_String endpointUrl;
    UA_String sessionName;
    UA_ByteString clientNonce;
    UA_ByteString clientCertificate;
    UA_Double requestedSessionTimeout;
    UA_UInt32 maxResponseMessageSize;
} UA_CreateSessionRequest;

#define UA_TYPES_CREATESESSIONREQUEST 63

/**
 * CreateSessionResponse
 * ^^^^^^^^^^^^^^^^^^^^^
 * Creates a new session with the server. */
typedef struct {
    UA_ResponseHeader responseHeader;
    UA_NodeId sessionId;
    UA_NodeId authenticationToken;
    UA_Double revisedSessionTimeout;
    UA_ByteString serverNonce;
    UA_ByteString serverCertificate;
    size_t serverEndpointsSize;
    UA_EndpointDescription *serverEndpoints;
    size_t serverSoftwareCertificatesSize;
    UA_SignedSoftwareCertificate *serverSoftwareCertificates;
    UA_SignatureData serverSignature;
    UA_UInt32 maxRequestMessageSize;
} UA_CreateSessionResponse;

#define UA_TYPES_CREATESESSIONRESPONSE 64

/**
 * UserIdentityToken
 * ^^^^^^^^^^^^^^^^^
 * A base type for a user identity token. */
typedef struct {
    UA_String policyId;
} UA_UserIdentityToken;

#define UA_TYPES_USERIDENTITYTOKEN 65

/**
 * AnonymousIdentityToken
 * ^^^^^^^^^^^^^^^^^^^^^^
 * A token representing an anonymous user. */
typedef struct {
    UA_String policyId;
} UA_AnonymousIdentityToken;

#define UA_TYPES_ANONYMOUSIDENTITYTOKEN 66

/**
 * UserNameIdentityToken
 * ^^^^^^^^^^^^^^^^^^^^^
 * A token representing a user identified by a user name and password. */
typedef struct {
    UA_String policyId;
    UA_String userName;
    UA_ByteString password;
    UA_String encryptionAlgorithm;
} UA_UserNameIdentityToken;

#define UA_TYPES_USERNAMEIDENTITYTOKEN 67

/**
 * X509IdentityToken
 * ^^^^^^^^^^^^^^^^^
 * A token representing a user identified by an X509 certificate. */
typedef struct {
    UA_String policyId;
    UA_ByteString certificateData;
} UA_X509IdentityToken;

#define UA_TYPES_X509IDENTITYTOKEN 68

/**
 * IssuedIdentityToken
 * ^^^^^^^^^^^^^^^^^^^
 * A token representing a user identified by a WS-Security XML token. */
typedef struct {
    UA_String policyId;
    UA_ByteString tokenData;
    UA_String encryptionAlgorithm;
} UA_IssuedIdentityToken;

#define UA_TYPES_ISSUEDIDENTITYTOKEN 69

/**
 * ActivateSessionRequest
 * ^^^^^^^^^^^^^^^^^^^^^^
 * Activates a session with the server. */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_SignatureData clientSignature;
    size_t clientSoftwareCertificatesSize;
    UA_SignedSoftwareCertificate *clientSoftwareCertificates;
    size_t localeIdsSize;
    UA_String *localeIds;
    UA_ExtensionObject userIdentityToken;
    UA_SignatureData userTokenSignature;
} UA_ActivateSessionRequest;

#define UA_TYPES_ACTIVATESESSIONREQUEST 70

/**
 * ActivateSessionResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^
 * Activates a session with the server. */
typedef struct {
    UA_ResponseHeader responseHeader;
    UA_ByteString serverNonce;
    size_t resultsSize;
    UA_StatusCode *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_ActivateSessionResponse;

#define UA_TYPES_ACTIVATESESSIONRESPONSE 71

/**
 * CloseSessionRequest
 * ^^^^^^^^^^^^^^^^^^^
 * Closes a session with the server. */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_Boolean deleteSubscriptions;
} UA_CloseSessionRequest;

#define UA_TYPES_CLOSESESSIONREQUEST 72

/**
 * CloseSessionResponse
 * ^^^^^^^^^^^^^^^^^^^^
 * Closes a session with the server. */
typedef struct {
    UA_ResponseHeader responseHeader;
} UA_CloseSessionResponse;

#define UA_TYPES_CLOSESESSIONRESPONSE 73

/**
 * NodeAttributesMask
 * ^^^^^^^^^^^^^^^^^^
 * The bits used to specify default attributes for a new node. */
typedef enum {
    UA_NODEATTRIBUTESMASK_NONE = 0,
    UA_NODEATTRIBUTESMASK_ACCESSLEVEL = 1,
    UA_NODEATTRIBUTESMASK_ARRAYDIMENSIONS = 2,
    UA_NODEATTRIBUTESMASK_BROWSENAME = 4,
    UA_NODEATTRIBUTESMASK_CONTAINSNOLOOPS = 8,
    UA_NODEATTRIBUTESMASK_DATATYPE = 16,
    UA_NODEATTRIBUTESMASK_DESCRIPTION = 32,
    UA_NODEATTRIBUTESMASK_DISPLAYNAME = 64,
    UA_NODEATTRIBUTESMASK_EVENTNOTIFIER = 128,
    UA_NODEATTRIBUTESMASK_EXECUTABLE = 256,
    UA_NODEATTRIBUTESMASK_HISTORIZING = 512,
    UA_NODEATTRIBUTESMASK_INVERSENAME = 1024,
    UA_NODEATTRIBUTESMASK_ISABSTRACT = 2048,
    UA_NODEATTRIBUTESMASK_MINIMUMSAMPLINGINTERVAL = 4096,
    UA_NODEATTRIBUTESMASK_NODECLASS = 8192,
    UA_NODEATTRIBUTESMASK_NODEID = 16384,
    UA_NODEATTRIBUTESMASK_SYMMETRIC = 32768,
    UA_NODEATTRIBUTESMASK_USERACCESSLEVEL = 65536,
    UA_NODEATTRIBUTESMASK_USEREXECUTABLE = 131072,
    UA_NODEATTRIBUTESMASK_USERWRITEMASK = 262144,
    UA_NODEATTRIBUTESMASK_VALUERANK = 524288,
    UA_NODEATTRIBUTESMASK_WRITEMASK = 1048576,
    UA_NODEATTRIBUTESMASK_VALUE = 2097152,
    UA_NODEATTRIBUTESMASK_DATATYPEDEFINITION = 4194304,
    UA_NODEATTRIBUTESMASK_ROLEPERMISSIONS = 8388608,
    UA_NODEATTRIBUTESMASK_ACCESSRESTRICTIONS = 16777216,
    UA_NODEATTRIBUTESMASK_ALL = 33554431,
    UA_NODEATTRIBUTESMASK_BASENODE = 26501220,
    UA_NODEATTRIBUTESMASK_OBJECT = 26501348,
    UA_NODEATTRIBUTESMASK_OBJECTTYPE = 26503268,
    UA_NODEATTRIBUTESMASK_VARIABLE = 26571383,
    UA_NODEATTRIBUTESMASK_VARIABLETYPE = 28600438,
    UA_NODEATTRIBUTESMASK_METHOD = 26632548,
    UA_NODEATTRIBUTESMASK_REFERENCETYPE = 26537060,
    UA_NODEATTRIBUTESMASK_VIEW = 26501356,
    __UA_NODEATTRIBUTESMASK_FORCE32BIT = 0x7fffffff
} UA_NodeAttributesMask;
UA_STATIC_ASSERT(sizeof(UA_NodeAttributesMask) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_NODEATTRIBUTESMASK 74

/**
 * NodeAttributes
 * ^^^^^^^^^^^^^^
 * The base attributes for all nodes. */
typedef struct {
    UA_UInt32 specifiedAttributes;
    UA_LocalizedText displayName;
    UA_LocalizedText description;
    UA_UInt32 writeMask;
    UA_UInt32 userWriteMask;
} UA_NodeAttributes;

#define UA_TYPES_NODEATTRIBUTES 75

/**
 * ObjectAttributes
 * ^^^^^^^^^^^^^^^^
 * The attributes for an object node. */
typedef struct {
    UA_UInt32 specifiedAttributes;
    UA_LocalizedText displayName;
    UA_LocalizedText description;
    UA_UInt32 writeMask;
    UA_UInt32 userWriteMask;
    UA_Byte eventNotifier;
} UA_ObjectAttributes;

#define UA_TYPES_OBJECTATTRIBUTES 76

/**
 * VariableAttributes
 * ^^^^^^^^^^^^^^^^^^
 * The attributes for a variable node. */
typedef struct {
    UA_UInt32 specifiedAttributes;
    UA_LocalizedText displayName;
    UA_LocalizedText description;
    UA_UInt32 writeMask;
    UA_UInt32 userWriteMask;
    UA_Variant value;
    UA_NodeId dataType;
    UA_Int32 valueRank;
    size_t arrayDimensionsSize;
    UA_UInt32 *arrayDimensions;
    UA_Byte accessLevel;
    UA_Byte userAccessLevel;
    UA_Double minimumSamplingInterval;
    UA_Boolean historizing;
} UA_VariableAttributes;

#define UA_TYPES_VARIABLEATTRIBUTES 77

/**
 * MethodAttributes
 * ^^^^^^^^^^^^^^^^
 * The attributes for a method node. */
typedef struct {
    UA_UInt32 specifiedAttributes;
    UA_LocalizedText displayName;
    UA_LocalizedText description;
    UA_UInt32 writeMask;
    UA_UInt32 userWriteMask;
    UA_Boolean executable;
    UA_Boolean userExecutable;
} UA_MethodAttributes;

#define UA_TYPES_METHODATTRIBUTES 78

/**
 * ObjectTypeAttributes
 * ^^^^^^^^^^^^^^^^^^^^
 * The attributes for an object type node. */
typedef struct {
    UA_UInt32 specifiedAttributes;
    UA_LocalizedText displayName;
    UA_LocalizedText description;
    UA_UInt32 writeMask;
    UA_UInt32 userWriteMask;
    UA_Boolean isAbstract;
} UA_ObjectTypeAttributes;

#define UA_TYPES_OBJECTTYPEATTRIBUTES 79

/**
 * VariableTypeAttributes
 * ^^^^^^^^^^^^^^^^^^^^^^
 * The attributes for a variable type node. */
typedef struct {
    UA_UInt32 specifiedAttributes;
    UA_LocalizedText displayName;
    UA_LocalizedText description;
    UA_UInt32 writeMask;
    UA_UInt32 userWriteMask;
    UA_Variant value;
    UA_NodeId dataType;
    UA_Int32 valueRank;
    size_t arrayDimensionsSize;
    UA_UInt32 *arrayDimensions;
    UA_Boolean isAbstract;
} UA_VariableTypeAttributes;

#define UA_TYPES_VARIABLETYPEATTRIBUTES 80

/**
 * ReferenceTypeAttributes
 * ^^^^^^^^^^^^^^^^^^^^^^^
 * The attributes for a reference type node. */
typedef struct {
    UA_UInt32 specifiedAttributes;
    UA_LocalizedText displayName;
    UA_LocalizedText description;
    UA_UInt32 writeMask;
    UA_UInt32 userWriteMask;
    UA_Boolean isAbstract;
    UA_Boolean symmetric;
    UA_LocalizedText inverseName;
} UA_ReferenceTypeAttributes;

#define UA_TYPES_REFERENCETYPEATTRIBUTES 81

/**
 * DataTypeAttributes
 * ^^^^^^^^^^^^^^^^^^
 * The attributes for a data type node. */
typedef struct {
    UA_UInt32 specifiedAttributes;
    UA_LocalizedText displayName;
    UA_LocalizedText description;
    UA_UInt32 writeMask;
    UA_UInt32 userWriteMask;
    UA_Boolean isAbstract;
} UA_DataTypeAttributes;

#define UA_TYPES_DATATYPEATTRIBUTES 82

/**
 * ViewAttributes
 * ^^^^^^^^^^^^^^
 * The attributes for a view node. */
typedef struct {
    UA_UInt32 specifiedAttributes;
    UA_LocalizedText displayName;
    UA_LocalizedText description;
    UA_UInt32 writeMask;
    UA_UInt32 userWriteMask;
    UA_Boolean containsNoLoops;
    UA_Byte eventNotifier;
} UA_ViewAttributes;

#define UA_TYPES_VIEWATTRIBUTES 83

/**
 * AddNodesItem
 * ^^^^^^^^^^^^
 * A request to add a node to the server address space. */
typedef struct {
    UA_ExpandedNodeId parentNodeId;
    UA_NodeId referenceTypeId;
    UA_ExpandedNodeId requestedNewNodeId;
    UA_QualifiedName browseName;
    UA_NodeClass nodeClass;
    UA_ExtensionObject nodeAttributes;
    UA_ExpandedNodeId typeDefinition;
} UA_AddNodesItem;

#define UA_TYPES_ADDNODESITEM 84

/**
 * AddNodesResult
 * ^^^^^^^^^^^^^^
 * A result of an add node operation. */
typedef struct {
    UA_StatusCode statusCode;
    UA_NodeId addedNodeId;
} UA_AddNodesResult;

#define UA_TYPES_ADDNODESRESULT 85

/**
 * AddNodesRequest
 * ^^^^^^^^^^^^^^^
 * Adds one or more nodes to the server address space. */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t nodesToAddSize;
    UA_AddNodesItem *nodesToAdd;
} UA_AddNodesRequest;

#define UA_TYPES_ADDNODESREQUEST 86

/**
 * AddNodesResponse
 * ^^^^^^^^^^^^^^^^
 * Adds one or more nodes to the server address space. */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_AddNodesResult *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_AddNodesResponse;

#define UA_TYPES_ADDNODESRESPONSE 87

/**
 * AddReferencesItem
 * ^^^^^^^^^^^^^^^^^
 * A request to add a reference to the server address space. */
typedef struct {
    UA_NodeId sourceNodeId;
    UA_NodeId referenceTypeId;
    UA_Boolean isForward;
    UA_String targetServerUri;
    UA_ExpandedNodeId targetNodeId;
    UA_NodeClass targetNodeClass;
} UA_AddReferencesItem;

#define UA_TYPES_ADDREFERENCESITEM 88

/**
 * AddReferencesRequest
 * ^^^^^^^^^^^^^^^^^^^^
 * Adds one or more references to the server address space. */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t referencesToAddSize;
    UA_AddReferencesItem *referencesToAdd;
} UA_AddReferencesRequest;

#define UA_TYPES_ADDREFERENCESREQUEST 89

/**
 * AddReferencesResponse
 * ^^^^^^^^^^^^^^^^^^^^^
 * Adds one or more references to the server address space. */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_StatusCode *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_AddReferencesResponse;

#define UA_TYPES_ADDREFERENCESRESPONSE 90

/**
 * DeleteNodesItem
 * ^^^^^^^^^^^^^^^
 * A request to delete a node to the server address space. */
typedef struct {
    UA_NodeId nodeId;
    UA_Boolean deleteTargetReferences;
} UA_DeleteNodesItem;

#define UA_TYPES_DELETENODESITEM 91

/**
 * DeleteNodesRequest
 * ^^^^^^^^^^^^^^^^^^
 * Delete one or more nodes from the server address space. */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t nodesToDeleteSize;
    UA_DeleteNodesItem *nodesToDelete;
} UA_DeleteNodesRequest;

#define UA_TYPES_DELETENODESREQUEST 92

/**
 * DeleteNodesResponse
 * ^^^^^^^^^^^^^^^^^^^
 * Delete one or more nodes from the server address space. */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_StatusCode *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_DeleteNodesResponse;

#define UA_TYPES_DELETENODESRESPONSE 93

/**
 * DeleteReferencesItem
 * ^^^^^^^^^^^^^^^^^^^^
 * A request to delete a node from the server address space. */
typedef struct {
    UA_NodeId sourceNodeId;
    UA_NodeId referenceTypeId;
    UA_Boolean isForward;
    UA_ExpandedNodeId targetNodeId;
    UA_Boolean deleteBidirectional;
} UA_DeleteReferencesItem;

#define UA_TYPES_DELETEREFERENCESITEM 94

/**
 * DeleteReferencesRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^
 * Delete one or more references from the server address space. */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t referencesToDeleteSize;
    UA_DeleteReferencesItem *referencesToDelete;
} UA_DeleteReferencesRequest;

#define UA_TYPES_DELETEREFERENCESREQUEST 95

/**
 * DeleteReferencesResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^
 * Delete one or more references from the server address space. */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_StatusCode *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_DeleteReferencesResponse;

#define UA_TYPES_DELETEREFERENCESRESPONSE 96

/**
 * BrowseDirection
 * ^^^^^^^^^^^^^^^
 * The directions of the references to return. */
typedef enum {
    UA_BROWSEDIRECTION_FORWARD = 0,
    UA_BROWSEDIRECTION_INVERSE = 1,
    UA_BROWSEDIRECTION_BOTH = 2,
    UA_BROWSEDIRECTION_INVALID = 3,
    __UA_BROWSEDIRECTION_FORCE32BIT = 0x7fffffff
} UA_BrowseDirection;
UA_STATIC_ASSERT(sizeof(UA_BrowseDirection) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_BROWSEDIRECTION 97

/**
 * ViewDescription
 * ^^^^^^^^^^^^^^^
 * The view to browse. */
typedef struct {
    UA_NodeId viewId;
    UA_DateTime timestamp;
    UA_UInt32 viewVersion;
} UA_ViewDescription;

#define UA_TYPES_VIEWDESCRIPTION 98

/**
 * BrowseDescription
 * ^^^^^^^^^^^^^^^^^
 * A request to browse the the references from a node. */
typedef struct {
    UA_NodeId nodeId;
    UA_BrowseDirection browseDirection;
    UA_NodeId referenceTypeId;
    UA_Boolean includeSubtypes;
    UA_UInt32 nodeClassMask;
    UA_UInt32 resultMask;
} UA_BrowseDescription;

#define UA_TYPES_BROWSEDESCRIPTION 99

/**
 * BrowseResultMask
 * ^^^^^^^^^^^^^^^^
 * A bit mask which specifies what should be returned in a browse response. */
typedef enum {
    UA_BROWSERESULTMASK_NONE = 0,
    UA_BROWSERESULTMASK_REFERENCETYPEID = 1,
    UA_BROWSERESULTMASK_ISFORWARD = 2,
    UA_BROWSERESULTMASK_NODECLASS = 4,
    UA_BROWSERESULTMASK_BROWSENAME = 8,
    UA_BROWSERESULTMASK_DISPLAYNAME = 16,
    UA_BROWSERESULTMASK_TYPEDEFINITION = 32,
    UA_BROWSERESULTMASK_ALL = 63,
    UA_BROWSERESULTMASK_REFERENCETYPEINFO = 3,
    UA_BROWSERESULTMASK_TARGETINFO = 60,
    __UA_BROWSERESULTMASK_FORCE32BIT = 0x7fffffff
} UA_BrowseResultMask;
UA_STATIC_ASSERT(sizeof(UA_BrowseResultMask) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_BROWSERESULTMASK 100

/**
 * ReferenceDescription
 * ^^^^^^^^^^^^^^^^^^^^
 * The description of a reference. */
typedef struct {
    UA_NodeId referenceTypeId;
    UA_Boolean isForward;
    UA_ExpandedNodeId nodeId;
    UA_QualifiedName browseName;
    UA_LocalizedText displayName;
    UA_NodeClass nodeClass;
    UA_ExpandedNodeId typeDefinition;
} UA_ReferenceDescription;

#define UA_TYPES_REFERENCEDESCRIPTION 101

/**
 * BrowseResult
 * ^^^^^^^^^^^^
 * The result of a browse operation. */
typedef struct {
    UA_StatusCode statusCode;
    UA_ByteString continuationPoint;
    size_t referencesSize;
    UA_ReferenceDescription *references;
} UA_BrowseResult;

#define UA_TYPES_BROWSERESULT 102

/**
 * BrowseRequest
 * ^^^^^^^^^^^^^
 * Browse the references for one or more nodes from the server address space. */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_ViewDescription view;
    UA_UInt32 requestedMaxReferencesPerNode;
    size_t nodesToBrowseSize;
    UA_BrowseDescription *nodesToBrowse;
} UA_BrowseRequest;

#define UA_TYPES_BROWSEREQUEST 103

/**
 * BrowseResponse
 * ^^^^^^^^^^^^^^
 * Browse the references for one or more nodes from the server address space. */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_BrowseResult *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_BrowseResponse;

#define UA_TYPES_BROWSERESPONSE 104

/**
 * BrowseNextRequest
 * ^^^^^^^^^^^^^^^^^
 * Continues one or more browse operations. */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_Boolean releaseContinuationPoints;
    size_t continuationPointsSize;
    UA_ByteString *continuationPoints;
} UA_BrowseNextRequest;

#define UA_TYPES_BROWSENEXTREQUEST 105

/**
 * BrowseNextResponse
 * ^^^^^^^^^^^^^^^^^^
 * Continues one or more browse operations. */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_BrowseResult *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_BrowseNextResponse;

#define UA_TYPES_BROWSENEXTRESPONSE 106

/**
 * RelativePathElement
 * ^^^^^^^^^^^^^^^^^^^
 * An element in a relative path. */
typedef struct {
    UA_NodeId referenceTypeId;
    UA_Boolean isInverse;
    UA_Boolean includeSubtypes;
    UA_QualifiedName targetName;
} UA_RelativePathElement;

#define UA_TYPES_RELATIVEPATHELEMENT 107

/**
 * RelativePath
 * ^^^^^^^^^^^^
 * A relative path constructed from reference types and browse names. */
typedef struct {
    size_t elementsSize;
    UA_RelativePathElement *elements;
} UA_RelativePath;

#define UA_TYPES_RELATIVEPATH 108

/**
 * BrowsePath
 * ^^^^^^^^^^
 * A request to translate a path into a node id. */
typedef struct {
    UA_NodeId startingNode;
    UA_RelativePath relativePath;
} UA_BrowsePath;

#define UA_TYPES_BROWSEPATH 109

/**
 * BrowsePathTarget
 * ^^^^^^^^^^^^^^^^
 * The target of the translated path. */
typedef struct {
    UA_ExpandedNodeId targetId;
    UA_UInt32 remainingPathIndex;
} UA_BrowsePathTarget;

#define UA_TYPES_BROWSEPATHTARGET 110

/**
 * BrowsePathResult
 * ^^^^^^^^^^^^^^^^
 * The result of a translate opearation. */
typedef struct {
    UA_StatusCode statusCode;
    size_t targetsSize;
    UA_BrowsePathTarget *targets;
} UA_BrowsePathResult;

#define UA_TYPES_BROWSEPATHRESULT 111

/**
 * TranslateBrowsePathsToNodeIdsRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Translates one or more paths in the server address space. */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t browsePathsSize;
    UA_BrowsePath *browsePaths;
} UA_TranslateBrowsePathsToNodeIdsRequest;

#define UA_TYPES_TRANSLATEBROWSEPATHSTONODEIDSREQUEST 112

/**
 * TranslateBrowsePathsToNodeIdsResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Translates one or more paths in the server address space. */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_BrowsePathResult *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_TranslateBrowsePathsToNodeIdsResponse;

#define UA_TYPES_TRANSLATEBROWSEPATHSTONODEIDSRESPONSE 113

/**
 * RegisterNodesRequest
 * ^^^^^^^^^^^^^^^^^^^^
 * Registers one or more nodes for repeated use within a session. */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t nodesToRegisterSize;
    UA_NodeId *nodesToRegister;
} UA_RegisterNodesRequest;

#define UA_TYPES_REGISTERNODESREQUEST 114

/**
 * RegisterNodesResponse
 * ^^^^^^^^^^^^^^^^^^^^^
 * Registers one or more nodes for repeated use within a session. */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t registeredNodeIdsSize;
    UA_NodeId *registeredNodeIds;
} UA_RegisterNodesResponse;

#define UA_TYPES_REGISTERNODESRESPONSE 115

/**
 * UnregisterNodesRequest
 * ^^^^^^^^^^^^^^^^^^^^^^
 * Unregisters one or more previously registered nodes. */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t nodesToUnregisterSize;
    UA_NodeId *nodesToUnregister;
} UA_UnregisterNodesRequest;

#define UA_TYPES_UNREGISTERNODESREQUEST 116

/**
 * UnregisterNodesResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^
 * Unregisters one or more previously registered nodes. */
typedef struct {
    UA_ResponseHeader responseHeader;
} UA_UnregisterNodesResponse;

#define UA_TYPES_UNREGISTERNODESRESPONSE 117

/**
 * FilterOperator
 * ^^^^^^^^^^^^^^
 */
typedef enum {
    UA_FILTEROPERATOR_EQUALS = 0,
    UA_FILTEROPERATOR_ISNULL = 1,
    UA_FILTEROPERATOR_GREATERTHAN = 2,
    UA_FILTEROPERATOR_LESSTHAN = 3,
    UA_FILTEROPERATOR_GREATERTHANOREQUAL = 4,
    UA_FILTEROPERATOR_LESSTHANOREQUAL = 5,
    UA_FILTEROPERATOR_LIKE = 6,
    UA_FILTEROPERATOR_NOT = 7,
    UA_FILTEROPERATOR_BETWEEN = 8,
    UA_FILTEROPERATOR_INLIST = 9,
    UA_FILTEROPERATOR_AND = 10,
    UA_FILTEROPERATOR_OR = 11,
    UA_FILTEROPERATOR_CAST = 12,
    UA_FILTEROPERATOR_INVIEW = 13,
    UA_FILTEROPERATOR_OFTYPE = 14,
    UA_FILTEROPERATOR_RELATEDTO = 15,
    UA_FILTEROPERATOR_BITWISEAND = 16,
    UA_FILTEROPERATOR_BITWISEOR = 17,
    __UA_FILTEROPERATOR_FORCE32BIT = 0x7fffffff
} UA_FilterOperator;
UA_STATIC_ASSERT(sizeof(UA_FilterOperator) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_FILTEROPERATOR 118

/**
 * ContentFilterElement
 * ^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_FilterOperator filterOperator;
    size_t filterOperandsSize;
    UA_ExtensionObject *filterOperands;
} UA_ContentFilterElement;

#define UA_TYPES_CONTENTFILTERELEMENT 119

/**
 * ContentFilter
 * ^^^^^^^^^^^^^
 */
typedef struct {
    size_t elementsSize;
    UA_ContentFilterElement *elements;
} UA_ContentFilter;

#define UA_TYPES_CONTENTFILTER 120

/**
 * FilterOperand
 * ^^^^^^^^^^^^^
 */
typedef void * UA_FilterOperand;

#define UA_TYPES_FILTEROPERAND 121

/**
 * ElementOperand
 * ^^^^^^^^^^^^^^
 */
typedef struct {
    UA_UInt32 index;
} UA_ElementOperand;

#define UA_TYPES_ELEMENTOPERAND 122

/**
 * LiteralOperand
 * ^^^^^^^^^^^^^^
 */
typedef struct {
    UA_Variant value;
} UA_LiteralOperand;

#define UA_TYPES_LITERALOPERAND 123

/**
 * AttributeOperand
 * ^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_NodeId nodeId;
    UA_String alias;
    UA_RelativePath browsePath;
    UA_UInt32 attributeId;
    UA_String indexRange;
} UA_AttributeOperand;

#define UA_TYPES_ATTRIBUTEOPERAND 124

/**
 * SimpleAttributeOperand
 * ^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_NodeId typeDefinitionId;
    size_t browsePathSize;
    UA_QualifiedName *browsePath;
    UA_UInt32 attributeId;
    UA_String indexRange;
} UA_SimpleAttributeOperand;

#define UA_TYPES_SIMPLEATTRIBUTEOPERAND 125

/**
 * ContentFilterElementResult
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_StatusCode statusCode;
    size_t operandStatusCodesSize;
    UA_StatusCode *operandStatusCodes;
    size_t operandDiagnosticInfosSize;
    UA_DiagnosticInfo *operandDiagnosticInfos;
} UA_ContentFilterElementResult;

#define UA_TYPES_CONTENTFILTERELEMENTRESULT 126

/**
 * ContentFilterResult
 * ^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    size_t elementResultsSize;
    UA_ContentFilterElementResult *elementResults;
    size_t elementDiagnosticInfosSize;
    UA_DiagnosticInfo *elementDiagnosticInfos;
} UA_ContentFilterResult;

#define UA_TYPES_CONTENTFILTERRESULT 127

/**
 * TimestampsToReturn
 * ^^^^^^^^^^^^^^^^^^
 */
typedef enum {
    UA_TIMESTAMPSTORETURN_SOURCE = 0,
    UA_TIMESTAMPSTORETURN_SERVER = 1,
    UA_TIMESTAMPSTORETURN_BOTH = 2,
    UA_TIMESTAMPSTORETURN_NEITHER = 3,
    UA_TIMESTAMPSTORETURN_INVALID = 4,
    __UA_TIMESTAMPSTORETURN_FORCE32BIT = 0x7fffffff
} UA_TimestampsToReturn;
UA_STATIC_ASSERT(sizeof(UA_TimestampsToReturn) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_TIMESTAMPSTORETURN 128

/**
 * ReadValueId
 * ^^^^^^^^^^^
 */
typedef struct {
    UA_NodeId nodeId;
    UA_UInt32 attributeId;
    UA_String indexRange;
    UA_QualifiedName dataEncoding;
} UA_ReadValueId;

#define UA_TYPES_READVALUEID 129

/**
 * ReadRequest
 * ^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_Double maxAge;
    UA_TimestampsToReturn timestampsToReturn;
    size_t nodesToReadSize;
    UA_ReadValueId *nodesToRead;
} UA_ReadRequest;

#define UA_TYPES_READREQUEST 130

/**
 * ReadResponse
 * ^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_DataValue *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_ReadResponse;

#define UA_TYPES_READRESPONSE 131

/**
 * HistoryReadValueId
 * ^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_NodeId nodeId;
    UA_String indexRange;
    UA_QualifiedName dataEncoding;
    UA_ByteString continuationPoint;
} UA_HistoryReadValueId;

#define UA_TYPES_HISTORYREADVALUEID 132

/**
 * HistoryReadResult
 * ^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_StatusCode statusCode;
    UA_ByteString continuationPoint;
    UA_ExtensionObject historyData;
} UA_HistoryReadResult;

#define UA_TYPES_HISTORYREADRESULT 133

/**
 * ReadRawModifiedDetails
 * ^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_Boolean isReadModified;
    UA_DateTime startTime;
    UA_DateTime endTime;
    UA_UInt32 numValuesPerNode;
    UA_Boolean returnBounds;
} UA_ReadRawModifiedDetails;

#define UA_TYPES_READRAWMODIFIEDDETAILS 134

/**
 * ReadAtTimeDetails
 * ^^^^^^^^^^^^^^^^^
 */
typedef struct {
    size_t reqTimesSize;
    UA_DateTime *reqTimes;
    UA_Boolean useSimpleBounds;
} UA_ReadAtTimeDetails;

#define UA_TYPES_READATTIMEDETAILS 135

/**
 * HistoryData
 * ^^^^^^^^^^^
 */
typedef struct {
    size_t dataValuesSize;
    UA_DataValue *dataValues;
} UA_HistoryData;

#define UA_TYPES_HISTORYDATA 136

/**
 * HistoryReadRequest
 * ^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_ExtensionObject historyReadDetails;
    UA_TimestampsToReturn timestampsToReturn;
    UA_Boolean releaseContinuationPoints;
    size_t nodesToReadSize;
    UA_HistoryReadValueId *nodesToRead;
} UA_HistoryReadRequest;

#define UA_TYPES_HISTORYREADREQUEST 137

/**
 * HistoryReadResponse
 * ^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_HistoryReadResult *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_HistoryReadResponse;

#define UA_TYPES_HISTORYREADRESPONSE 138

/**
 * WriteValue
 * ^^^^^^^^^^
 */
typedef struct {
    UA_NodeId nodeId;
    UA_UInt32 attributeId;
    UA_String indexRange;
    UA_DataValue value;
} UA_WriteValue;

#define UA_TYPES_WRITEVALUE 139

/**
 * WriteRequest
 * ^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t nodesToWriteSize;
    UA_WriteValue *nodesToWrite;
} UA_WriteRequest;

#define UA_TYPES_WRITEREQUEST 140

/**
 * WriteResponse
 * ^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_StatusCode *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_WriteResponse;

#define UA_TYPES_WRITERESPONSE 141

/**
 * HistoryUpdateType
 * ^^^^^^^^^^^^^^^^^
 */
typedef enum {
    UA_HISTORYUPDATETYPE_INSERT = 1,
    UA_HISTORYUPDATETYPE_REPLACE = 2,
    UA_HISTORYUPDATETYPE_UPDATE = 3,
    UA_HISTORYUPDATETYPE_DELETE = 4,
    __UA_HISTORYUPDATETYPE_FORCE32BIT = 0x7fffffff
} UA_HistoryUpdateType;
UA_STATIC_ASSERT(sizeof(UA_HistoryUpdateType) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_HISTORYUPDATETYPE 142

/**
 * PerformUpdateType
 * ^^^^^^^^^^^^^^^^^
 */
typedef enum {
    UA_PERFORMUPDATETYPE_INSERT = 1,
    UA_PERFORMUPDATETYPE_REPLACE = 2,
    UA_PERFORMUPDATETYPE_UPDATE = 3,
    UA_PERFORMUPDATETYPE_REMOVE = 4,
    __UA_PERFORMUPDATETYPE_FORCE32BIT = 0x7fffffff
} UA_PerformUpdateType;
UA_STATIC_ASSERT(sizeof(UA_PerformUpdateType) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_PERFORMUPDATETYPE 143

/**
 * UpdateDataDetails
 * ^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_NodeId nodeId;
    UA_PerformUpdateType performInsertReplace;
    size_t updateValuesSize;
    UA_DataValue *updateValues;
} UA_UpdateDataDetails;

#define UA_TYPES_UPDATEDATADETAILS 144

/**
 * DeleteRawModifiedDetails
 * ^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_NodeId nodeId;
    UA_Boolean isDeleteModified;
    UA_DateTime startTime;
    UA_DateTime endTime;
} UA_DeleteRawModifiedDetails;

#define UA_TYPES_DELETERAWMODIFIEDDETAILS 145

/**
 * HistoryUpdateResult
 * ^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_StatusCode statusCode;
    size_t operationResultsSize;
    UA_StatusCode *operationResults;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_HistoryUpdateResult;

#define UA_TYPES_HISTORYUPDATERESULT 146

/**
 * HistoryUpdateRequest
 * ^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t historyUpdateDetailsSize;
    UA_ExtensionObject *historyUpdateDetails;
} UA_HistoryUpdateRequest;

#define UA_TYPES_HISTORYUPDATEREQUEST 147

/**
 * HistoryUpdateResponse
 * ^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_HistoryUpdateResult *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_HistoryUpdateResponse;

#define UA_TYPES_HISTORYUPDATERESPONSE 148

/**
 * CallMethodRequest
 * ^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_NodeId objectId;
    UA_NodeId methodId;
    size_t inputArgumentsSize;
    UA_Variant *inputArguments;
} UA_CallMethodRequest;

#define UA_TYPES_CALLMETHODREQUEST 149

/**
 * CallMethodResult
 * ^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_StatusCode statusCode;
    size_t inputArgumentResultsSize;
    UA_StatusCode *inputArgumentResults;
    size_t inputArgumentDiagnosticInfosSize;
    UA_DiagnosticInfo *inputArgumentDiagnosticInfos;
    size_t outputArgumentsSize;
    UA_Variant *outputArguments;
} UA_CallMethodResult;

#define UA_TYPES_CALLMETHODRESULT 150

/**
 * CallRequest
 * ^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t methodsToCallSize;
    UA_CallMethodRequest *methodsToCall;
} UA_CallRequest;

#define UA_TYPES_CALLREQUEST 151

/**
 * CallResponse
 * ^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_CallMethodResult *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_CallResponse;

#define UA_TYPES_CALLRESPONSE 152

/**
 * MonitoringMode
 * ^^^^^^^^^^^^^^
 */
typedef enum {
    UA_MONITORINGMODE_DISABLED = 0,
    UA_MONITORINGMODE_SAMPLING = 1,
    UA_MONITORINGMODE_REPORTING = 2,
    __UA_MONITORINGMODE_FORCE32BIT = 0x7fffffff
} UA_MonitoringMode;
UA_STATIC_ASSERT(sizeof(UA_MonitoringMode) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_MONITORINGMODE 153

/**
 * DataChangeTrigger
 * ^^^^^^^^^^^^^^^^^
 */
typedef enum {
    UA_DATACHANGETRIGGER_STATUS = 0,
    UA_DATACHANGETRIGGER_STATUSVALUE = 1,
    UA_DATACHANGETRIGGER_STATUSVALUETIMESTAMP = 2,
    __UA_DATACHANGETRIGGER_FORCE32BIT = 0x7fffffff
} UA_DataChangeTrigger;
UA_STATIC_ASSERT(sizeof(UA_DataChangeTrigger) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_DATACHANGETRIGGER 154

/**
 * DeadbandType
 * ^^^^^^^^^^^^
 */
typedef enum {
    UA_DEADBANDTYPE_NONE = 0,
    UA_DEADBANDTYPE_ABSOLUTE = 1,
    UA_DEADBANDTYPE_PERCENT = 2,
    __UA_DEADBANDTYPE_FORCE32BIT = 0x7fffffff
} UA_DeadbandType;
UA_STATIC_ASSERT(sizeof(UA_DeadbandType) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_DEADBANDTYPE 155

/**
 * DataChangeFilter
 * ^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_DataChangeTrigger trigger;
    UA_UInt32 deadbandType;
    UA_Double deadbandValue;
} UA_DataChangeFilter;

#define UA_TYPES_DATACHANGEFILTER 156

/**
 * EventFilter
 * ^^^^^^^^^^^
 */
typedef struct {
    size_t selectClausesSize;
    UA_SimpleAttributeOperand *selectClauses;
    UA_ContentFilter whereClause;
} UA_EventFilter;

#define UA_TYPES_EVENTFILTER 157

/**
 * AggregateConfiguration
 * ^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_Boolean useServerCapabilitiesDefaults;
    UA_Boolean treatUncertainAsBad;
    UA_Byte percentDataBad;
    UA_Byte percentDataGood;
    UA_Boolean useSlopedExtrapolation;
} UA_AggregateConfiguration;

#define UA_TYPES_AGGREGATECONFIGURATION 158

/**
 * AggregateFilter
 * ^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_DateTime startTime;
    UA_NodeId aggregateType;
    UA_Double processingInterval;
    UA_AggregateConfiguration aggregateConfiguration;
} UA_AggregateFilter;

#define UA_TYPES_AGGREGATEFILTER 159

/**
 * EventFilterResult
 * ^^^^^^^^^^^^^^^^^
 */
typedef struct {
    size_t selectClauseResultsSize;
    UA_StatusCode *selectClauseResults;
    size_t selectClauseDiagnosticInfosSize;
    UA_DiagnosticInfo *selectClauseDiagnosticInfos;
    UA_ContentFilterResult whereClauseResult;
} UA_EventFilterResult;

#define UA_TYPES_EVENTFILTERRESULT 160

/**
 * MonitoringParameters
 * ^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_UInt32 clientHandle;
    UA_Double samplingInterval;
    UA_ExtensionObject filter;
    UA_UInt32 queueSize;
    UA_Boolean discardOldest;
} UA_MonitoringParameters;

#define UA_TYPES_MONITORINGPARAMETERS 161

/**
 * MonitoredItemCreateRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ReadValueId itemToMonitor;
    UA_MonitoringMode monitoringMode;
    UA_MonitoringParameters requestedParameters;
} UA_MonitoredItemCreateRequest;

#define UA_TYPES_MONITOREDITEMCREATEREQUEST 162

/**
 * MonitoredItemCreateResult
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_StatusCode statusCode;
    UA_UInt32 monitoredItemId;
    UA_Double revisedSamplingInterval;
    UA_UInt32 revisedQueueSize;
    UA_ExtensionObject filterResult;
} UA_MonitoredItemCreateResult;

#define UA_TYPES_MONITOREDITEMCREATERESULT 163

/**
 * CreateMonitoredItemsRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_UInt32 subscriptionId;
    UA_TimestampsToReturn timestampsToReturn;
    size_t itemsToCreateSize;
    UA_MonitoredItemCreateRequest *itemsToCreate;
} UA_CreateMonitoredItemsRequest;

#define UA_TYPES_CREATEMONITOREDITEMSREQUEST 164

/**
 * CreateMonitoredItemsResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_MonitoredItemCreateResult *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_CreateMonitoredItemsResponse;

#define UA_TYPES_CREATEMONITOREDITEMSRESPONSE 165

/**
 * MonitoredItemModifyRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_UInt32 monitoredItemId;
    UA_MonitoringParameters requestedParameters;
} UA_MonitoredItemModifyRequest;

#define UA_TYPES_MONITOREDITEMMODIFYREQUEST 166

/**
 * MonitoredItemModifyResult
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_StatusCode statusCode;
    UA_Double revisedSamplingInterval;
    UA_UInt32 revisedQueueSize;
    UA_ExtensionObject filterResult;
} UA_MonitoredItemModifyResult;

#define UA_TYPES_MONITOREDITEMMODIFYRESULT 167

/**
 * ModifyMonitoredItemsRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_UInt32 subscriptionId;
    UA_TimestampsToReturn timestampsToReturn;
    size_t itemsToModifySize;
    UA_MonitoredItemModifyRequest *itemsToModify;
} UA_ModifyMonitoredItemsRequest;

#define UA_TYPES_MODIFYMONITOREDITEMSREQUEST 168

/**
 * ModifyMonitoredItemsResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_MonitoredItemModifyResult *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_ModifyMonitoredItemsResponse;

#define UA_TYPES_MODIFYMONITOREDITEMSRESPONSE 169

/**
 * SetMonitoringModeRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_UInt32 subscriptionId;
    UA_MonitoringMode monitoringMode;
    size_t monitoredItemIdsSize;
    UA_UInt32 *monitoredItemIds;
} UA_SetMonitoringModeRequest;

#define UA_TYPES_SETMONITORINGMODEREQUEST 170

/**
 * SetMonitoringModeResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_StatusCode *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_SetMonitoringModeResponse;

#define UA_TYPES_SETMONITORINGMODERESPONSE 171

/**
 * SetTriggeringRequest
 * ^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_UInt32 subscriptionId;
    UA_UInt32 triggeringItemId;
    size_t linksToAddSize;
    UA_UInt32 *linksToAdd;
    size_t linksToRemoveSize;
    UA_UInt32 *linksToRemove;
} UA_SetTriggeringRequest;

#define UA_TYPES_SETTRIGGERINGREQUEST 172

/**
 * SetTriggeringResponse
 * ^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t addResultsSize;
    UA_StatusCode *addResults;
    size_t addDiagnosticInfosSize;
    UA_DiagnosticInfo *addDiagnosticInfos;
    size_t removeResultsSize;
    UA_StatusCode *removeResults;
    size_t removeDiagnosticInfosSize;
    UA_DiagnosticInfo *removeDiagnosticInfos;
} UA_SetTriggeringResponse;

#define UA_TYPES_SETTRIGGERINGRESPONSE 173

/**
 * DeleteMonitoredItemsRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_UInt32 subscriptionId;
    size_t monitoredItemIdsSize;
    UA_UInt32 *monitoredItemIds;
} UA_DeleteMonitoredItemsRequest;

#define UA_TYPES_DELETEMONITOREDITEMSREQUEST 174

/**
 * DeleteMonitoredItemsResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_StatusCode *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_DeleteMonitoredItemsResponse;

#define UA_TYPES_DELETEMONITOREDITEMSRESPONSE 175

/**
 * CreateSubscriptionRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_Double requestedPublishingInterval;
    UA_UInt32 requestedLifetimeCount;
    UA_UInt32 requestedMaxKeepAliveCount;
    UA_UInt32 maxNotificationsPerPublish;
    UA_Boolean publishingEnabled;
    UA_Byte priority;
} UA_CreateSubscriptionRequest;

#define UA_TYPES_CREATESUBSCRIPTIONREQUEST 176

/**
 * CreateSubscriptionResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    UA_UInt32 subscriptionId;
    UA_Double revisedPublishingInterval;
    UA_UInt32 revisedLifetimeCount;
    UA_UInt32 revisedMaxKeepAliveCount;
} UA_CreateSubscriptionResponse;

#define UA_TYPES_CREATESUBSCRIPTIONRESPONSE 177

/**
 * ModifySubscriptionRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_UInt32 subscriptionId;
    UA_Double requestedPublishingInterval;
    UA_UInt32 requestedLifetimeCount;
    UA_UInt32 requestedMaxKeepAliveCount;
    UA_UInt32 maxNotificationsPerPublish;
    UA_Byte priority;
} UA_ModifySubscriptionRequest;

#define UA_TYPES_MODIFYSUBSCRIPTIONREQUEST 178

/**
 * ModifySubscriptionResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    UA_Double revisedPublishingInterval;
    UA_UInt32 revisedLifetimeCount;
    UA_UInt32 revisedMaxKeepAliveCount;
} UA_ModifySubscriptionResponse;

#define UA_TYPES_MODIFYSUBSCRIPTIONRESPONSE 179

/**
 * SetPublishingModeRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_Boolean publishingEnabled;
    size_t subscriptionIdsSize;
    UA_UInt32 *subscriptionIds;
} UA_SetPublishingModeRequest;

#define UA_TYPES_SETPUBLISHINGMODEREQUEST 180

/**
 * SetPublishingModeResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_StatusCode *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_SetPublishingModeResponse;

#define UA_TYPES_SETPUBLISHINGMODERESPONSE 181

/**
 * NotificationMessage
 * ^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_UInt32 sequenceNumber;
    UA_DateTime publishTime;
    size_t notificationDataSize;
    UA_ExtensionObject *notificationData;
} UA_NotificationMessage;

#define UA_TYPES_NOTIFICATIONMESSAGE 182

/**
 * MonitoredItemNotification
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_UInt32 clientHandle;
    UA_DataValue value;
} UA_MonitoredItemNotification;

#define UA_TYPES_MONITOREDITEMNOTIFICATION 183

/**
 * EventFieldList
 * ^^^^^^^^^^^^^^
 */
typedef struct {
    UA_UInt32 clientHandle;
    size_t eventFieldsSize;
    UA_Variant *eventFields;
} UA_EventFieldList;

#define UA_TYPES_EVENTFIELDLIST 184

/**
 * HistoryEventFieldList
 * ^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    size_t eventFieldsSize;
    UA_Variant *eventFields;
} UA_HistoryEventFieldList;

#define UA_TYPES_HISTORYEVENTFIELDLIST 185

/**
 * StatusChangeNotification
 * ^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_StatusCode status;
    UA_DiagnosticInfo diagnosticInfo;
} UA_StatusChangeNotification;

#define UA_TYPES_STATUSCHANGENOTIFICATION 186

/**
 * SubscriptionAcknowledgement
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_UInt32 subscriptionId;
    UA_UInt32 sequenceNumber;
} UA_SubscriptionAcknowledgement;

#define UA_TYPES_SUBSCRIPTIONACKNOWLEDGEMENT 187

/**
 * PublishRequest
 * ^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t subscriptionAcknowledgementsSize;
    UA_SubscriptionAcknowledgement *subscriptionAcknowledgements;
} UA_PublishRequest;

#define UA_TYPES_PUBLISHREQUEST 188

/**
 * PublishResponse
 * ^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    UA_UInt32 subscriptionId;
    size_t availableSequenceNumbersSize;
    UA_UInt32 *availableSequenceNumbers;
    UA_Boolean moreNotifications;
    UA_NotificationMessage notificationMessage;
    size_t resultsSize;
    UA_StatusCode *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_PublishResponse;

#define UA_TYPES_PUBLISHRESPONSE 189

/**
 * RepublishRequest
 * ^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    UA_UInt32 subscriptionId;
    UA_UInt32 retransmitSequenceNumber;
} UA_RepublishRequest;

#define UA_TYPES_REPUBLISHREQUEST 190

/**
 * RepublishResponse
 * ^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    UA_NotificationMessage notificationMessage;
} UA_RepublishResponse;

#define UA_TYPES_REPUBLISHRESPONSE 191

/**
 * DeleteSubscriptionsRequest
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_RequestHeader requestHeader;
    size_t subscriptionIdsSize;
    UA_UInt32 *subscriptionIds;
} UA_DeleteSubscriptionsRequest;

#define UA_TYPES_DELETESUBSCRIPTIONSREQUEST 192

/**
 * DeleteSubscriptionsResponse
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_ResponseHeader responseHeader;
    size_t resultsSize;
    UA_StatusCode *results;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_DeleteSubscriptionsResponse;

#define UA_TYPES_DELETESUBSCRIPTIONSRESPONSE 193

/**
 * BuildInfo
 * ^^^^^^^^^
 */
typedef struct {
    UA_String productUri;
    UA_String manufacturerName;
    UA_String productName;
    UA_String softwareVersion;
    UA_String buildNumber;
    UA_DateTime buildDate;
} UA_BuildInfo;

#define UA_TYPES_BUILDINFO 194

/**
 * RedundancySupport
 * ^^^^^^^^^^^^^^^^^
 */
typedef enum {
    UA_REDUNDANCYSUPPORT_NONE = 0,
    UA_REDUNDANCYSUPPORT_COLD = 1,
    UA_REDUNDANCYSUPPORT_WARM = 2,
    UA_REDUNDANCYSUPPORT_HOT = 3,
    UA_REDUNDANCYSUPPORT_TRANSPARENT = 4,
    UA_REDUNDANCYSUPPORT_HOTANDMIRRORED = 5,
    __UA_REDUNDANCYSUPPORT_FORCE32BIT = 0x7fffffff
} UA_RedundancySupport;
UA_STATIC_ASSERT(sizeof(UA_RedundancySupport) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_REDUNDANCYSUPPORT 195

/**
 * ServerState
 * ^^^^^^^^^^^
 */
typedef enum {
    UA_SERVERSTATE_RUNNING = 0,
    UA_SERVERSTATE_FAILED = 1,
    UA_SERVERSTATE_NOCONFIGURATION = 2,
    UA_SERVERSTATE_SUSPENDED = 3,
    UA_SERVERSTATE_SHUTDOWN = 4,
    UA_SERVERSTATE_TEST = 5,
    UA_SERVERSTATE_COMMUNICATIONFAULT = 6,
    UA_SERVERSTATE_UNKNOWN = 7,
    __UA_SERVERSTATE_FORCE32BIT = 0x7fffffff
} UA_ServerState;
UA_STATIC_ASSERT(sizeof(UA_ServerState) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_SERVERSTATE 196

/**
 * ServerDiagnosticsSummaryDataType
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_UInt32 serverViewCount;
    UA_UInt32 currentSessionCount;
    UA_UInt32 cumulatedSessionCount;
    UA_UInt32 securityRejectedSessionCount;
    UA_UInt32 rejectedSessionCount;
    UA_UInt32 sessionTimeoutCount;
    UA_UInt32 sessionAbortCount;
    UA_UInt32 currentSubscriptionCount;
    UA_UInt32 cumulatedSubscriptionCount;
    UA_UInt32 publishingIntervalCount;
    UA_UInt32 securityRejectedRequestsCount;
    UA_UInt32 rejectedRequestsCount;
} UA_ServerDiagnosticsSummaryDataType;

#define UA_TYPES_SERVERDIAGNOSTICSSUMMARYDATATYPE 197

/**
 * ServerStatusDataType
 * ^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_DateTime startTime;
    UA_DateTime currentTime;
    UA_ServerState state;
    UA_BuildInfo buildInfo;
    UA_UInt32 secondsTillShutdown;
    UA_LocalizedText shutdownReason;
} UA_ServerStatusDataType;

#define UA_TYPES_SERVERSTATUSDATATYPE 198

/**
 * Range
 * ^^^^^
 */
typedef struct {
    UA_Double low;
    UA_Double high;
} UA_Range;

#define UA_TYPES_RANGE 199

/**
 * ReadEventDetails
 * ^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_UInt32 numValuesPerNode;
    UA_DateTime startTime;
    UA_DateTime endTime;
    UA_EventFilter filter;
} UA_ReadEventDetails;

#define UA_TYPES_READEVENTDETAILS 200

/**
 * ReadProcessedDetails
 * ^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_DateTime startTime;
    UA_DateTime endTime;
    UA_Double processingInterval;
    size_t aggregateTypeSize;
    UA_NodeId *aggregateType;
    UA_AggregateConfiguration aggregateConfiguration;
} UA_ReadProcessedDetails;

#define UA_TYPES_READPROCESSEDDETAILS 201

/**
 * ModificationInfo
 * ^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_DateTime modificationTime;
    UA_HistoryUpdateType updateType;
    UA_String userName;
} UA_ModificationInfo;

#define UA_TYPES_MODIFICATIONINFO 202

/**
 * HistoryModifiedData
 * ^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    size_t dataValuesSize;
    UA_DataValue *dataValues;
    size_t modificationInfosSize;
    UA_ModificationInfo *modificationInfos;
} UA_HistoryModifiedData;

#define UA_TYPES_HISTORYMODIFIEDDATA 203

/**
 * HistoryEvent
 * ^^^^^^^^^^^^
 */
typedef struct {
    size_t eventsSize;
    UA_HistoryEventFieldList *events;
} UA_HistoryEvent;

#define UA_TYPES_HISTORYEVENT 204

/**
 * DataChangeNotification
 * ^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    size_t monitoredItemsSize;
    UA_MonitoredItemNotification *monitoredItems;
    size_t diagnosticInfosSize;
    UA_DiagnosticInfo *diagnosticInfos;
} UA_DataChangeNotification;

#define UA_TYPES_DATACHANGENOTIFICATION 205

/**
 * EventNotificationList
 * ^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    size_t eventsSize;
    UA_EventFieldList *events;
} UA_EventNotificationList;

#define UA_TYPES_EVENTNOTIFICATIONLIST 206


_UA_END_DECLS

#endif /* TYPES_GENERATED_H_ */
