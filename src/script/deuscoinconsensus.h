// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Deuscoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DEUSCOIN_DEUSCOINCONSENSUS_H
#define DEUSCOIN_DEUSCOINCONSENSUS_H

#if defined(BUILD_DEUSCOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/deuscoin-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBDEUSCOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define DEUSCOINCONSENSUS_API_VER 0

typedef enum deuscoinconsensus_error_t
{
    deuscoinconsensus_ERR_OK = 0,
    deuscoinconsensus_ERR_TX_INDEX,
    deuscoinconsensus_ERR_TX_SIZE_MISMATCH,
    deuscoinconsensus_ERR_TX_DESERIALIZE,
} deuscoinconsensus_error;

/** Script verification flags */
enum
{
    deuscoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    deuscoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    deuscoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    deuscoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not NULL, err will contain an error/success code for the operation
EXPORT_SYMBOL int deuscoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, deuscoinconsensus_error* err);

EXPORT_SYMBOL unsigned int deuscoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // DEUSCOIN_DEUSCOINCONSENSUS_H
