package battleshipModel;

/**
 * enum określający, wartość pola na planszy przeciwnika
 */
public enum BoxTypeFromMessage {
	MISS_MESSAGE,HIT_MESSAGE,SUNK_MESSAGE,INITIALIZE_MESSAGE //initialize_message is used only when I initialize listener
}
