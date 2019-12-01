void proximoEstagio() {
	switch(estagioAtual) {
    case ESTAGIO_INICIAL:
    	estagioAtual = ESTAGIO_TRANSPORTE;
    	break;

    case ESTAGIO_TRANSPORTE:
    	estagioAtual = ESTAGIO_RETORNO;
    	break;

    case ESTAGIO_RETORNO:
    	estagioAtual = ESTAGIO_INICIAL;
    	break;

    default:
    	estagioAtual = ESTAGIO_INICIAL;
  }
}