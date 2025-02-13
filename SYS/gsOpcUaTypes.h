/**
 * @file
 *
 *
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 26.02.2020
 */


#ifndef GSOPCUATYPES_H_INCLUDED
#define GSOPCUATYPES_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

typedef enum eagGsOpcUaPolicyType
{
    GSOPCUA_POLICY_NONE,
    GSOPCUA_POLICY_BASIC128RSA15,
    GSOPCUA_POLICY_BASIC256,
    GSOPCUA_POLICY_BASIC256SHA256,
} eGsOpcUaPolicyType;

typedef enum eagGsOpcUaLogLevel
{
    GSOPCUA_LOGLEVEL_NONE,
    GSOPCUA_LOGLEVEL_FATAL,
    GSOPCUA_LOGLEVEL_ERROR,
    GSOPCUA_LOGLEVEL_WARNING,
    GSOPCUA_LOGLEVEL_INFO,
    GSOPCUA_LOGLEVEL_DEBUG,
    GSOPCUA_LOGLEVEL_TRACE
} eGsOpcUaLogLevel;

typedef struct tagGsOpcUaLogin
{
    char * mUsername;
    char * mPassword;
} tGsOpcUaLogin;

/**
 * Create certificate and key with openssl using these commands:
 * $ openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:2048 -keyout privatekey.key -out certificate.crt
 * $ openssl x509 -in certificate.crt -outform der -out certificate.der
 * $ openssl rsa -inform PEM -in privatekey.key -outform DER -out privatekey.der
 */
typedef struct tagGsOpcUaSecurityPolicy
{
    eGsOpcUaPolicyType mType;
    char * mCertificatePath;
    char * mPrivateKeyPath;
} tGsOpcUaSecurityPolicy;

typedef void(*tGsOpcUaServerLogCallback)(char * msg);

typedef struct tagGsOpcUaServerConfig
{
    uint16_t mPort;

    uint8_t mAllowAnonymous;
    tGsOpcUaLogin * mLogin;
    size_t mNumLogins;
    tGsOpcUaSecurityPolicy mPolicy;

    uint32_t * mVariables;
    int32_t mNumVariables;

    char ** mUserCFunctions;
    int32_t mNumUserCFunctions;

    tGsOpcUaServerLogCallback mLogCb;
    eGsOpcUaLogLevel mLogLevel;
} tGsOpcUaServerConfig;

typedef struct tagGsOpcUaServer tGsOpcUaServer;
typedef tGsOpcUaServer * tGsOpcUaServerHdl;
//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

#endif //GSOPCUATYPES_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
