#ifndef QRCODEG_H
#define QRCODEG_H

#endif // QRCODEG_H
#if !defined(AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_)
#define AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////

//
#define QR_LEVEL_L	0
#define QR_LEVEL_M	1
#define QR_LEVEL_Q	2
#define QR_LEVEL_H	3

//
#define QR_MODE_NUMERAL		0
#define QR_MODE_ALPHABET	1
#define QR_MODE_8BIT		2
#define QR_MODE_KANJI		3

//
#define QR_VRESION_S	0
#define QR_VRESION_M	1
#define QR_VRESION_L	2

#define MAX_ALLCODEWORD	 3706
#define MAX_DATACODEWORD 2956
#define MAX_CODEBLOCK	  153
#define MAX_MODULESIZE	  177

#define QR_MARGIN	4


/////////////////////////////////////////////////////////////////////////////
typedef struct tagRS_BLOCKINFO
{
    int ncRSBlock;
    int ncAllCodeWord;
    int ncDataCodeWord;

} RS_BLOCKINFO, *LPRS_BLOCKINFO;


/////////////////////////////////////////////////////////////////////////////

typedef struct tagQR_VERSIONINFO
{
    int nVersionNo;
    int ncAllCodeWord;

    int ncDataCodeWord[4];

    int ncAlignPoint;
    int nAlignPoint[6];

    RS_BLOCKINFO RS_BlockInfo1[4];
    RS_BLOCKINFO RS_BlockInfo2[4];

} QR_VERSIONINFO, *LPQR_VERSIONINFO;


/////////////////////////////////////////////////////////////////////////////

class CQR_Encode   //CQR_Encode qui est utilisée pour encoder des données en code QR
{
public:
    CQR_Encode();
    ~CQR_Encode();

public:
    int m_nLevel;
    int m_nVersion;
    bool m_bAutoExtent;
    int m_nMaskingNo;

public:
    int m_nSymbleSize;
    unsigned char m_byModuleData[MAX_MODULESIZE][MAX_MODULESIZE]; // [x][y]
// c'est un tableau bidimensionnel de caractères non signés (unsigned char)
private:
    int m_ncDataCodeWordBit;
    unsigned char m_byDataCodeWord[MAX_DATACODEWORD];

    int m_ncDataBlock;
    unsigned char m_byBlockMode[MAX_DATACODEWORD];
    int m_nBlockLength[MAX_DATACODEWORD];

    int m_ncAllCodeWord;
    unsigned char m_byAllCodeWord[MAX_ALLCODEWORD];
    unsigned char m_byRSWork[MAX_CODEBLOCK];

public:
    bool EncodeData(int nLevel, int nVersion, bool bAutoExtent, int nMaskingNo, char* lpsSource, int ncSource = 0);
//pour encoder les données dans un code QR
    /*nLevel : le niveau de correction d'erreur (L, M, Q ou H)
nVersion : la version du QR code (1 à 40)
bAutoExtent : si vrai, la version du QR code sera automatiquement étendue pour contenir toutes les données, sinon, une erreur sera retournée si les données ne rentrent pas dans la version donnée
nMaskingNo : le numéro de motif de masquage à utiliser (0 à 7)
lpsSource : la chaîne de caractères à encoder
ncSource : le nombre de caractères dans la chaîne (si 0, la longueur sera déterminée automatiquement)
La fonction retourne un booléen indiquant si l'encodage a réussi ou non.*/
private:
    int GetEncodeVersion(int nVersion, char* lpsSource, int ncLength);
    bool EncodeSourceData(char* lpsSource, int ncLength, int nVerGroup);

    int GetBitLength(unsigned char nMode, int ncData, int nVerGroup);

    int SetBitStream(int nIndex, unsigned short wData, int ncData);

    bool IsNumeralData(unsigned char c);//vérifie si le caractère fourni est un chiffre numérique.
    bool IsAlphabetData(unsigned char c);// vérifie si le caractère fourni est une lettre majuscule ou minuscule de l'alphabet.
    bool IsKanjiData(unsigned char c1, unsigned char c2);//ette fonction vérifie si les deux octets fournis représentent un caractère Kanji.

    unsigned char AlphabetToBinaly(unsigned char c);//Cette fonction convertit un caractère de l'alphabet en code binaire.
    unsigned short KanjiToBinaly(unsigned short wc);

    void GetRSCodeWord(unsigned char * lpbyRSWork, int ncDataCodeWord, int ncRSCodeWord);
// calcule les codes de correction d'erreur Reed-Solomon pour les mots de code de données spécifiés.
private:
    void FormatModule();//Définit les modules de fonction

    void SetFunctionModule();
    void SetFinderPattern(int x, int y);// est utilisé pour dessiner les motifs de recherche.
    void SetAlignmentPattern(int x, int y);//est utilisé pour dessiner les motifs d'alignement
    void SetVersionPattern();//est utilisé pour dessiner le motif de version.
    //Le motif de version est un motif qui contient des informations sur la version du symbole de code QR.
    void SetCodeWordPattern();//est utilisé pour dessiner le motif de mot de code.
    void SetMaskingPattern(int nPatternNo);//applique un motif de masquage à la matrice de données du code QR
    void SetFormatInfoPattern(int nPatternNo);//applique le format d'information au code QR en utilisant l'algorithme de masquage de Reed-Solomon
    int CountPenalty();//calcule la pénalité pour la matrice de données du code QR en utilisant les règles de pénalité de l'ISO/IEC 18004:2006
};

/////////////////////////////////////////////////////////////////////////////

#endif // !defined(AFX_QR_ENCODE_H__AC886DF7_C0AE_4C9F_AC7A_FCDA8CB1DD37__INCLUDED_)
