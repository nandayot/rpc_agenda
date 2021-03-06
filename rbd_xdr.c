/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rbd.h"

bool_t
xdr_nametype (XDR *xdrs, nametype *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, MAXNAMELEN))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_Agenda (XDR *xdrs, Agenda *objp)
{
	register int32_t *buf;

	 if (!xdr_nametype (xdrs, &objp->nome))
		 return FALSE;
	 if (!xdr_nametype (xdrs, &objp->telefone))
		 return FALSE;
	 if (!xdr_nametype (xdrs, &objp->endereco))
		 return FALSE;
	 if (!xdr_nametype (xdrs, &objp->email))
		 return FALSE;
	return TRUE;
}
