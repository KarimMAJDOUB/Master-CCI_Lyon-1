#include <windows.h>
#include "resource.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
   BOOL TOP;
   BOOL BOTTOM;
   BOOL SIDE;
} PROPRIETE ;



int nombre=2, nb_objet=0;
struct
{
   bool TOP;
   bool BOTTOM;
   bool SIDE;
   bool On;
} prop ;

bool choix_texture;
bool texture=false;
HWND hwndcombo, hwndcombo2;
HWND hwndcombo3, hwndcombo4; 
double x,y,z,t,theta, X, Y, Z;

TCHAR text0[]=TEXT("<aucune>");
TCHAR text1[]=TEXT("dalles.jpg");
TCHAR text2[]=TEXT("gravier.jpg");
TCHAR text3[]=TEXT("herbe.jpg");
TCHAR text4[]=TEXT("metal_rouil.jpg");
TCHAR text5[]=TEXT("mi-neige.jpg");
TCHAR text6[]=TEXT("mur.jpg");
TCHAR text7[]=TEXT("papier.jpg");
TCHAR text8[]=TEXT("paves.jpg");
TCHAR text9[]=TEXT("quadrillage.jpg");
TCHAR text10[]=TEXT("tole_rouil.jpg");
TCHAR text11[]=TEXT("eau.jpg");
TCHAR text12[]=TEXT("WRLPOOL.mpg");
TCHAR text13[]=TEXT("SERIF");
TCHAR text14[]=TEXT("SANS");
TCHAR text15[]=TEXT("TYPEWRITER");
TCHAR text16[]=TEXT("BOLD");
TCHAR text17[]=TEXT("PLAIN");
TCHAR text18[]=TEXT("ITALIC");
TCHAR text19[]=TEXT("BOLDITALIC");



char urll[30],url2[30];
char url3[30],url4[30];


double mat[12];
char chaine[100];


FILE *fich;
FILE *S;

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

TCHAR szAppName[] = TEXT ("prog") ;




int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     HWND     hwnd ;
     MSG      msg ;
     WNDCLASS wndclass ;
     
     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU1);
     wndclass.lpszClassName = szAppName ;

     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, TEXT ("Ce programme fonctionne exclusivement sous Windows NT!"),
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }
     
     hwnd = CreateWindow (szAppName, TEXT ("Interface VRML"),
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;
     
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     
     while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;

}





LRESULT CALLBACK matiere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
TCHAR vIDC_ambientIntensity[10]=TEXT("0.2"),vIDC_DIFFX[10]=TEXT("0.8"),vIDC_DIFFY[10]=TEXT("0.8"),vIDC_DIFFZ[10]=TEXT("0.8"),
		vIDC_EMX[10]=TEXT("0"),vIDC_EMY[10]=TEXT("0"),vIDC_EMZ[10]=TEXT("0"),vIDC_BRIL[10]=TEXT("0.2"),
		vIDC_SPECX[10]=TEXT("0"),vIDC_SPECY[10]=TEXT("0"),vIDC_SPECZ[10]=TEXT("0"),vIDC_TRANSP[10]=TEXT("0");
	
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText(hwnd, IDC_ambientIntensity,vIDC_ambientIntensity);

			SetDlgItemText(hwnd, IDC_DIFFX,vIDC_DIFFX);
			SetDlgItemText(hwnd, IDC_DIFFY,vIDC_DIFFY);
			SetDlgItemText(hwnd, IDC_DIFFZ,vIDC_DIFFZ);
			SetDlgItemText(hwnd, IDC_EMX,vIDC_EMX);
			SetDlgItemText(hwnd, IDC_EMY,vIDC_EMY);
			SetDlgItemText(hwnd, IDC_EMZ,vIDC_EMZ);
			SetDlgItemText(hwnd, IDC_BRILL,vIDC_BRIL);
			SetDlgItemText(hwnd, IDC_SPECX,vIDC_SPECX);
			SetDlgItemText(hwnd, IDC_SPECY,vIDC_SPECY);
			SetDlgItemText(hwnd, IDC_SPECZ,vIDC_SPECZ);
			SetDlgItemText(hwnd, IDC_TRANSP,vIDC_TRANSP);

		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd, IDC_ambientIntensity,vIDC_ambientIntensity,10);
					GetDlgItemText(hwnd, IDC_DIFFX,vIDC_DIFFX,10);
					GetDlgItemText(hwnd, IDC_DIFFY,vIDC_DIFFY,10);
					GetDlgItemText(hwnd, IDC_DIFFZ,vIDC_DIFFZ,10);
					GetDlgItemText(hwnd, IDC_EMX,vIDC_EMX,10);
					GetDlgItemText(hwnd, IDC_EMY,vIDC_EMY,10);
					GetDlgItemText(hwnd, IDC_EMZ,vIDC_EMZ,10);
					GetDlgItemText(hwnd, IDC_BRILL,vIDC_BRIL,10);
					GetDlgItemText(hwnd, IDC_SPECX,vIDC_SPECX,10);
					GetDlgItemText(hwnd, IDC_SPECY,vIDC_SPECY,10);
					GetDlgItemText(hwnd, IDC_SPECZ,vIDC_SPECZ,10);
					GetDlgItemText(hwnd, IDC_TRANSP,vIDC_TRANSP,10);

                   	mat[0] = _wtof(vIDC_ambientIntensity);
					mat[1] = _wtof(vIDC_DIFFX);
					mat[2] = _wtof(vIDC_DIFFY);
					mat[3] = _wtof(vIDC_DIFFZ);
					mat[4] = _wtof(vIDC_EMX);
					mat[5] = _wtof(vIDC_EMY);
					mat[6] = _wtof(vIDC_EMZ);
					mat[7] = _wtof(vIDC_BRIL);
					mat[8] = _wtof(vIDC_SPECX);
					mat[9] = _wtof(vIDC_SPECY);
					mat[10] = _wtof(vIDC_SPECZ);
					mat[11] = _wtof(vIDC_TRANSP);
						
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

/************************************************************/
LRESULT CALLBACK cylindre(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Rayon[10]=TEXT("1.0"),vIDC_Hauteur[10]=TEXT("2.0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			SetDlgItemText( hwnd, IDC_Hauteur,vIDC_Hauteur);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckDlgButton(hwnd, IDC_BAS, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_HAUT, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_COTE, BST_CHECKED);
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_Rayon,vIDC_Rayon,10);
					GetDlgItemText(hwnd,IDC_Hauteur,vIDC_Hauteur,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					if(IsDlgButtonChecked(hwnd, IDC_HAUT) == BST_CHECKED)
                                                       prop.TOP = TRUE;
                    else  prop.TOP = FALSE;

                   if(IsDlgButtonChecked(hwnd, IDC_BAS) == BST_CHECKED)
                                                      prop.BOTTOM = TRUE;
                    else  prop.BOTTOM = FALSE;
					if(IsDlgButtonChecked(hwnd, IDC_COTE) == BST_CHECKED)
                                                      prop.SIDE = TRUE;
                    else  prop.SIDE = FALSE;
                    if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED) choix_texture = TRUE;
					else choix_texture = FALSE;
					
					++nb_objet;
                   	fopen_s(&fich,"toto.wrl","a");
                    fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}

                    if(choix_texture) 
					{
					  if (strcmp(urll,"<aucune>")==0) texture=false;
					  if (!texture)
					  {
					
					   fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					  }
					}
					else
					{
						if (strcmp(url2,"<aucune>")==0) texture=false;
					  if (!texture)
					  {
					
					   fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					  }
					}
					
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Cylinder{\n");
					fwprintf(fich,L"radius %s \n height %s\n",vIDC_Rayon, vIDC_Hauteur);
					if(!prop.TOP) fprintf(fich, "top TRUE\n");
					if(!prop.BOTTOM) fprintf(fich, "bottom TRUE\n");
					if(!prop.SIDE) fprintf(fich, "side TRUE\n");
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}
/**********************************************************/
LRESULT CALLBACK CONE(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Radius[10]=TEXT("1.0"),vIDC_Height[10]=TEXT("2.0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Radius,vIDC_Radius);
			SetDlgItemText( hwnd, IDC_Height,vIDC_Height);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckDlgButton(hwnd, IDC_BAS, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_COTE, BST_CHECKED);
			CheckRadioButton(hwnd, IDC_COMBO_FIXE, IDC_COMBO_ANIME, IDC_COMBO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_Radius,vIDC_Radius,10);
					GetDlgItemText(hwnd,IDC_Height,vIDC_Height,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					

                   if(IsDlgButtonChecked(hwnd, IDC_BAS) == BST_CHECKED)
                                                      prop.BOTTOM = TRUE;
                    else  prop.BOTTOM = FALSE;
					if(IsDlgButtonChecked(hwnd, IDC_COTE) == BST_CHECKED)
                                                      prop.SIDE = TRUE;
                    else  prop.SIDE = FALSE;
                    if(IsDlgButtonChecked(hwnd, IDC_COMBO_FIXE) == BST_CHECKED) choix_texture = TRUE;
					else choix_texture = FALSE;
					
					++nb_objet;
                   	fopen_s(&fich,"toto.wrl","a");
                    fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}

                    if(choix_texture) 
					{
					  if (strcmp(urll,"<aucune>")==0) texture=false;
					  if (!texture)
					  {
					
					   fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					  }
					}
					else
					{
						if (strcmp(url2,"<aucune>")==0) texture=false;
					  if (!texture)
					  {
					
					   fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					  }
					}
					
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Cone{\n");
					fwprintf(fich,L"bottomRadius %s \n height %s\n",vIDC_Radius, vIDC_Height);
					if(!prop.BOTTOM) fprintf(fich, "bottom TRUE\n");
					if(!prop.SIDE) fprintf(fich, "side TRUE\n");
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

/*********************************************************/

LRESULT CALLBACK sphere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Rayon[10]=TEXT("1.0"),vIDC_Hauteur[10]=TEXT("2.0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
		
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_Rayon,vIDC_Rayon,10);
					
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					
                    if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED) choix_texture = TRUE;
					else choix_texture = FALSE;
					
					++nb_objet;
                   	fopen_s(&fich,"toto.wrl","a");
                    fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}

                    if(choix_texture) 
					{
					  if (strcmp(urll,"<aucune>")==0) texture=false;
					  if (!texture)
					  {
					
					   fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					  }
					}
					else
					{
						if (strcmp(url2,"<aucune>")==0) texture=false;
					  if (!texture)
					  {
					
					   fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					  }
					}
					
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Sphere{\n");
					fwprintf(fich,L"radius %s \n",vIDC_Rayon);
			
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

/********************************/
LRESULT CALLBACK Texte(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_TXT[10]= TEXT("Bonjour");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_TEXT1,vIDC_TXT);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);

			hwndcombo3 = GetDlgItem (hwnd, IDC_COMBO_Police);
			hwndcombo4 = GetDlgItem (hwnd, IDC_COMBO_Style);

			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text13);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text14);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) text15);
			SendMessage(hwndcombo3, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) text16);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) text17);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) text18);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) text19);
			SendMessage(hwndcombo4, CB_SETCURSEL , 0, 0);
			
			CheckRadioButton(hwnd, IDC_COMBO_FIXE, IDC_COMBO_ANIME, IDC_RADIO_FIXE);
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_TEXT1,vIDC_TXT,10);
			
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);

					SendDlgItemMessage(hwnd, IDC_COMBO_Police,WM_GETTEXT, sizeof(url3),(LPARAM) url3);
					SendDlgItemMessage(hwnd, IDC_COMBO_Style,WM_GETTEXT, sizeof(url4),(LPARAM) url4);

                    if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED) choix_texture = TRUE;
					else choix_texture = FALSE;
					
					++nb_objet;
                   	fopen_s(&fich,"toto.wrl","a");
                    fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}

                    if(choix_texture) 
					{
					  if (strcmp(urll,"<aucune>")==0) texture=false;
					  if (!texture)
					  {
					
					   fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					  }
					}
					else
					{
						if (strcmp(url2,"<aucune>")==0) texture=false;
					  if (!texture)
					  {
					
					   fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					  }
					}
					
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Text{\n");
					fwprintf(fich, L"string [\"\ %s\"]\n", vIDC_TXT);
					fwprintf(fich,L"fontStyle FontStyle {\n");
					fwprintf(fich,L"family \"\%s\" \n",  url3);
					fwprintf(fich,L"style \"\%s\" \n",  url4 );
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fprintf(fich,"}\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;
				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}
/*******************************/

LRESULT CALLBACK Box(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_X[10]=TEXT("2.0"),vIDC_Y[10]=TEXT("2.0"),vIDC_Z[10]=TEXT("2.0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_X,vIDC_X);
			SetDlgItemText( hwnd, IDC_Y,vIDC_Y);
			SetDlgItemText( hwnd, IDC_Z,vIDC_Z);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_X,vIDC_X,10);
					GetDlgItemText(hwnd,IDC_Y,vIDC_Y,10);
					GetDlgItemText(hwnd,IDC_Z,vIDC_Z,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
				
                    if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED) choix_texture = TRUE;
					else choix_texture = FALSE;
					
					++nb_objet;
                   	fopen_s(&fich,"toto.wrl","a");
                    fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");

					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}

                    if(choix_texture) 
					{
					  if (strcmp(urll,"<aucune>")==0) texture=false;
					  if (!texture)
					  {
					
					   fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
					  }
					}
					else
					{
						if (strcmp(url2,"<aucune>")==0) texture=false;
					  if (!texture)
					  {
					
					   fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					  }
					}
					
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Box{\n");
					fwprintf(fich,L"size %s %s %s \n", vIDC_X, vIDC_Y, vIDC_Z);
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}
//
/************************************* SENSOR CYLINDRE *****************************************************/


LRESULT CALLBACK cylSensor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
TCHAR vIDC_MINIANGLE[10]=TEXT("0"), vIDC_MAXIANGLE[10]=TEXT("-1"),vIDC_DISKANGLE[10]=TEXT("0.262"),vIDC_OFFSET1[10]=TEXT("0");
		
	   
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText(hwnd, IDC_MINANGLE,vIDC_MINIANGLE);
			SetDlgItemText(hwnd, IDC_MAXANGLE,vIDC_MAXIANGLE);
			SetDlgItemText(hwnd, IDC_DISKANGLE,vIDC_DISKANGLE);
			SetDlgItemText(hwnd, IDC_OFFSET,vIDC_OFFSET1);

			
			CheckDlgButton(hwnd, IDC_AUTOOFFSET, BST_CHECKED);
			
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd, IDC_MINANGLE,vIDC_MINIANGLE,10);
					GetDlgItemText(hwnd, IDC_MAXANGLE,vIDC_MAXIANGLE,10);
					GetDlgItemText(hwnd, IDC_DISKANGLE,vIDC_DISKANGLE,10);
					GetDlgItemText(hwnd, IDC_OFFSET,vIDC_OFFSET1,10);
					
					
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF cylsensor CylinderSensor {\n");
				if(IsDlgButtonChecked(hwnd, IDC_AUTOOFFSET) == BST_CHECKED) 
					fprintf(fich,"autoOffset TRUE\n");
				else fprintf(fich,"autoOffset FALSE\n");
					
					fprintf(fich,"diskAngle %g \n",_wtof(vIDC_DISKANGLE));
					fprintf(fich,"maxAngle %g \n",_wtof(vIDC_MAXIANGLE));
					fprintf(fich,"minAngle %g \n",_wtof(vIDC_MINIANGLE));
					fprintf(fich,"offset %g \n",_wtof(vIDC_OFFSET1));

					fprintf(fich," }\n");
					fclose(fich);
					fopen_s(&S,"toto1.wrl","a");
										
					fprintf(S,"ROUTE cylsensor.rotation_changed TO objet%d.set_rotation \n",nb_objet);
					fprintf(S," \n");
					fclose(S);
					
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					EndDialog(hwnd, 0);
					return 0;
			}
		return 0;
	}
	return 0;
}
/************************************* SENSOR plan *****************************************************/


LRESULT CALLBACK planSensor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
TCHAR vIDC_MINposition0[10]=TEXT("0"),vIDC_MINposition1[10]=TEXT("0"),
	vIDC_MAXposition0[10]=TEXT("-1"),vIDC_MAXposition1[10]=TEXT("-1"),
	vIDC_OFFSET1[10]=TEXT("0"),vIDC_OFFSET2[10]=TEXT("0"),vIDC_OFFSET3[10]=TEXT("0");
		
	   
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText(hwnd, IDC_MINposition1,vIDC_MINposition0);
			SetDlgItemText(hwnd, IDC_MINposition2,vIDC_MINposition1);
			SetDlgItemText(hwnd, IDC_MAXposition1,vIDC_MAXposition0);
			SetDlgItemText(hwnd, IDC_MAXposition2,vIDC_MAXposition1);
			SetDlgItemText(hwnd, IDC_OFFSET,vIDC_OFFSET1);
			SetDlgItemText(hwnd, IDC_OFFSET2,vIDC_OFFSET2);
			SetDlgItemText(hwnd, IDC_OFFSET3,vIDC_OFFSET3);
			
			CheckDlgButton(hwnd, IDC_AUTOOFFSET, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_enabled, BST_CHECKED);
			
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd, IDC_MINposition1,vIDC_MINposition0,10);
					GetDlgItemText(hwnd, IDC_MINposition2,vIDC_MINposition1,10);
					GetDlgItemText(hwnd, IDC_MAXposition1,vIDC_MAXposition0,10);
					GetDlgItemText(hwnd, IDC_MAXposition2,vIDC_MAXposition1,10);
					GetDlgItemText(hwnd, IDC_OFFSET,vIDC_OFFSET1,10);
					GetDlgItemText(hwnd, IDC_OFFSET2,vIDC_OFFSET2,10);
					GetDlgItemText(hwnd, IDC_OFFSET3,vIDC_OFFSET3,10);
					
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF PS PlaneSensor {\n");
				if(IsDlgButtonChecked(hwnd, IDC_AUTOOFFSET) == BST_CHECKED) fprintf(fich,"autoOffset TRUE\n");
				else fprintf(fich,"autoOffset FALSE\n");
				if(IsDlgButtonChecked(hwnd, IDC_enabled) == BST_CHECKED) fprintf(fich,"enabled TRUE\n");
				else fprintf(fich,"enabled FALSE\n");
					
					fprintf(fich,"maxPosition %g %g \n",_wtof(vIDC_MAXposition0),_wtof(vIDC_MAXposition1));
					fprintf(fich,"minPosition %g %g \n",_wtof(vIDC_MINposition0),_wtof(vIDC_MINposition1));
					fprintf(fich,"offset %g %g %g \n",_wtof(vIDC_OFFSET1),_wtof(vIDC_OFFSET2),_wtof(vIDC_OFFSET3));

					fprintf(fich," }\n");
					fclose(fich);

					fopen_s(&S,"toto1.wrl","a");
										
					fprintf(S,"ROUTE PS.translation_changed TO objet%d.set_translation \n",nb_objet);
					fprintf(S," \n");
					fclose(S);
					
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					EndDialog(hwnd, 0);
					return 0;
			}
		return 0;
	}
	return 0;
}
/************************************* SENSOR plan *****************************************************/


LRESULT CALLBACK SphereSensor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
TCHAR vIDC_OFFSET0[10]=TEXT("0"),vIDC_OFFSET1[10]=TEXT("1"),vIDC_OFFSET2[10]=TEXT("0"),vIDC_OFFSET3[10]=TEXT("0");
		
	   
    
	switch (msg) {
		case WM_INITDIALOG :
			
			SetDlgItemText(hwnd, IDC_OFFSET1,vIDC_OFFSET0);
			SetDlgItemText(hwnd, IDC_OFFSET2,vIDC_OFFSET1);
			SetDlgItemText(hwnd, IDC_OFFSET3,vIDC_OFFSET2);
			SetDlgItemText(hwnd, IDC_OFFSET4,vIDC_OFFSET3);
			CheckDlgButton(hwnd, IDC_AUTOOFFSET, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_enabled, BST_CHECKED);
			
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					
					GetDlgItemText(hwnd, IDC_OFFSET1,vIDC_OFFSET0,10);
					GetDlgItemText(hwnd, IDC_OFFSET2,vIDC_OFFSET1,10);
					GetDlgItemText(hwnd, IDC_OFFSET3,vIDC_OFFSET2,10);
					GetDlgItemText(hwnd, IDC_OFFSET4,vIDC_OFFSET3,10);
					
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF tourneur SphereSensor {\n");
				if(IsDlgButtonChecked(hwnd, IDC_AUTOOFFSET) == BST_CHECKED) fprintf(fich,"autoOffset TRUE\n");
				else fprintf(fich,"autoOffset FALSE\n");
				if(IsDlgButtonChecked(hwnd, IDC_enabled) == BST_CHECKED) fprintf(fich,"enabled TRUE\n");
				else fprintf(fich,"enabled FALSE\n");
					
					fprintf(fich,"offset %g %g %g %g \n",_wtof(vIDC_OFFSET0),_wtof(vIDC_OFFSET1),_wtof(vIDC_OFFSET2),_wtof(vIDC_OFFSET3));

					fprintf(fich," }\n");
					fclose(fich);

					fopen_s(&S,"toto1.wrl","a");
										
					fprintf(S,"ROUTE tourneur.rotation_changed TO objet%d.set_rotation \n",nb_objet);
					fprintf(S," \n");
					fclose(S);
					
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					EndDialog(hwnd, 0);
					return 0;
			}
		return 0;
	}
	return 0;
}
LRESULT CALLBACK LUMIERE_SPOT(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	TCHAR vIDC_IA1[10]=TEXT("0"),vIDC_I1[10]=TEXT("1"),vIDC_R1[10]=TEXT("100"),vIDC_L1[10]=TEXT("0"),vIDC_L2[10]=TEXT("0"),vIDC_L3[10]=TEXT("0"),
		  vIDC_A1[10]=TEXT("1.0"),vIDC_A2[10]=TEXT("0.0"),vIDC_A3[10]=TEXT("0.0"),  
		  vIDC_C1[10]=TEXT("1"),vIDC_C2[10]=TEXT("1"),vIDC_C3[10]=TEXT("1"),
		  vIDC_D1[10]=TEXT("0"),vIDC_D2[10]=TEXT("0"),vIDC_D3[10]=TEXT("-1"),vIDC_cuto[10]=TEXT("0.785398"),vIDC_beam[10]=TEXT("1.570796");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_IA1,vIDC_IA1 );
			SetDlgItemText( hwnd, IDC_I1,vIDC_I1 );
			SetDlgItemText( hwnd, IDC_R1,vIDC_R1 );
			SetDlgItemText( hwnd, IDC_L1,vIDC_L1);
			SetDlgItemText( hwnd, IDC_L2,vIDC_L2);
			SetDlgItemText( hwnd, IDC_L3,vIDC_L3);
			SetDlgItemText( hwnd, IDC_A1,vIDC_A1);
			SetDlgItemText( hwnd, IDC_A2,vIDC_A2);
			SetDlgItemText( hwnd, IDC_A3,vIDC_A3);
			SetDlgItemText( hwnd, IDC_C1,vIDC_C1 );
			SetDlgItemText( hwnd, IDC_C2,vIDC_C2 );
			SetDlgItemText( hwnd, IDC_C3,vIDC_C3 );
			SetDlgItemText( hwnd, IDC_D1,vIDC_D1);
			SetDlgItemText( hwnd, IDC_D2,vIDC_D2);
			SetDlgItemText( hwnd, IDC_D3,vIDC_D3);
			SetDlgItemText( hwnd, IDC_cuto,vIDC_cuto);
			SetDlgItemText( hwnd, IDC_beam,vIDC_beam);
			
			
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_IA1,vIDC_IA1,10);
					GetDlgItemText(hwnd,IDC_I1,vIDC_I1,10);
					GetDlgItemText(hwnd,IDC_R1,vIDC_R1,10);
					GetDlgItemText(hwnd,IDC_L1,vIDC_L1,10);
					GetDlgItemText(hwnd,IDC_L2,vIDC_L2,10);
					GetDlgItemText(hwnd,IDC_L3,vIDC_L3,10);
					GetDlgItemText(hwnd,IDC_A1,vIDC_A1,10);
					GetDlgItemText(hwnd,IDC_A2,vIDC_A2,10);
					GetDlgItemText(hwnd,IDC_A3,vIDC_A3,10);
					GetDlgItemText(hwnd,IDC_C1,vIDC_C1,10);
					GetDlgItemText(hwnd,IDC_C2,vIDC_C2,10);
					GetDlgItemText(hwnd,IDC_C3,vIDC_C3,10);
					GetDlgItemText(hwnd,IDC_D1,vIDC_D1,10);
					GetDlgItemText(hwnd,IDC_D2,vIDC_D2,10);
					GetDlgItemText(hwnd,IDC_D3,vIDC_D3,10);
					GetDlgItemText(hwnd,IDC_cuto,vIDC_cuto,10);
					GetDlgItemText(hwnd,IDC_beam,vIDC_beam,10);
					

					
					

                   	fopen_s(&fich,"toto.wrl","a");
                    fprintf(fich,"SpotLight{\n");
					fwprintf(fich,L"ambientIntensity %s\n",vIDC_IA1);
					fwprintf(fich,L"attenuation %s %s %s\n",vIDC_A1,vIDC_A2,vIDC_A3);
					fwprintf(fich,L"beamWidth %s\n", vIDC_beam);
					fwprintf(fich,L"color %s %s %s \n",vIDC_C1,vIDC_C2,vIDC_C3);
					fwprintf(fich,L"cutOffAngle %s\n", vIDC_cuto);
					fwprintf(fich,L"direction %s %s %s\n",vIDC_D1,vIDC_D2,vIDC_D3);
					fwprintf(fich,L"intensity %s\n", vIDC_I1);
					fwprintf(fich,L"location %s %s %s\n",vIDC_L1,vIDC_L2,vIDC_L3);
					fwprintf(fich,L"radius %s\n", vIDC_R1);
	


					fprintf(fich,"}\n");
					
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;
					EndDialog(hwnd, 1);
					return 0;
			
				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;


				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}
/****************************************************/
LRESULT CALLBACK LUMIERE_DIRECTIONNELLE(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_IA0[10]=TEXT("0"),vIDC_I0[10]=TEXT("1"),vIDC_C0[10]=TEXT("1"),vIDC_C1[10]=TEXT("1"),vIDC_C2[10]=TEXT("1"),
		  vIDC_D0[10]=TEXT("0"),vIDC_D1[10]=TEXT("0"),vIDC_D2[10]=TEXT("-1");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_IA1,vIDC_IA0 );
			SetDlgItemText( hwnd, IDC_I1,vIDC_I0 );
			SetDlgItemText( hwnd, IDC_C1,vIDC_C0 );
			SetDlgItemText( hwnd, IDC_C2,vIDC_C1 );
			SetDlgItemText( hwnd, IDC_C3,vIDC_C2 );
			SetDlgItemText( hwnd, IDC_D1,vIDC_D0);
			SetDlgItemText( hwnd, IDC_D2,vIDC_D1);
			SetDlgItemText( hwnd, IDC_D3,vIDC_D2);
			
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_IA1,vIDC_IA0,10);
					GetDlgItemText(hwnd,IDC_I1,vIDC_I0,10);
					GetDlgItemText(hwnd,IDC_C1,vIDC_C0,10);
					GetDlgItemText(hwnd,IDC_C2,vIDC_C1,10);
					GetDlgItemText(hwnd,IDC_C3,vIDC_C2,10);
					GetDlgItemText(hwnd,IDC_D1,vIDC_D0,10);
					GetDlgItemText(hwnd,IDC_D2,vIDC_D1,10);
					GetDlgItemText(hwnd,IDC_D3,vIDC_D2,10);
			

                   	fopen_s(&fich,"toto.wrl","a");
                    fprintf(fich,"SpotLight{\n");
					fwprintf(fich,L"ambientIntensity %s\n",vIDC_IA0);
					fwprintf(fich,L"color %s %s %s\n",vIDC_C1,vIDC_C2,vIDC_C2);
					fwprintf(fich,L"direction %s %s %s\n",vIDC_D1,vIDC_D2,vIDC_D2);
					fwprintf(fich,L"intensity %s\n", vIDC_I0);
					
	
					fprintf(fich,"}\n");
					
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;
					EndDialog(hwnd, 1);
					return 0;
			
				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;


				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

/**************************************************/

LRESULT CALLBACK LUMIERE_PONCTUELLE(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_IA0[10]=TEXT("0"), vIDC_A0[10]=TEXT("1.0"),vIDC_A1[10]=TEXT("0.0"),vIDC_A2[10]=TEXT("0.0"), 
		vIDC_C0[10]=TEXT("1"),vIDC_C1[10]=TEXT("1"),vIDC_C2[10]=TEXT("1"),
		vIDC_I0[10]=TEXT("1"),vIDC_L0[10]=TEXT("0"),vIDC_L1[10]=TEXT("0"),vIDC_L2[10]=TEXT("0"),vIDC_R0[10]=TEXT("100") ;
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_IA1,vIDC_IA0 );
			SetDlgItemText( hwnd, IDC_A1,vIDC_A0);
			SetDlgItemText( hwnd, IDC_A2,vIDC_A1);
			SetDlgItemText( hwnd, IDC_A3,vIDC_A2);
			SetDlgItemText( hwnd, IDC_C1,vIDC_C0 );
			SetDlgItemText( hwnd, IDC_C2,vIDC_C1 );
			SetDlgItemText( hwnd, IDC_C3,vIDC_C2 );
			SetDlgItemText( hwnd, IDC_I1,vIDC_I0 );
			SetDlgItemText( hwnd, IDC_L1,vIDC_L0);
			SetDlgItemText( hwnd, IDC_L2,vIDC_L1);
			SetDlgItemText( hwnd, IDC_L3,vIDC_L2);
			SetDlgItemText( hwnd, IDC_R1,vIDC_R0);
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_IA1,vIDC_IA0,10);
					GetDlgItemText(hwnd,IDC_A1,vIDC_A0,10);
					GetDlgItemText(hwnd,IDC_A2,vIDC_A1,10);
					GetDlgItemText(hwnd,IDC_A3,vIDC_A2,10);
					GetDlgItemText(hwnd,IDC_C1,vIDC_C0,10);
					GetDlgItemText(hwnd,IDC_C2,vIDC_C1,10);
					GetDlgItemText(hwnd,IDC_C3,vIDC_C2,10);
					GetDlgItemText(hwnd,IDC_I1,vIDC_I0,10);
					GetDlgItemText(hwnd,IDC_L1,vIDC_L0,10);
					GetDlgItemText(hwnd,IDC_L2,vIDC_L1,10);
					GetDlgItemText(hwnd,IDC_L3,vIDC_L2,10);
					GetDlgItemText(hwnd,IDC_R1,vIDC_R0,10);
					

                   	fopen_s(&fich,"toto.wrl","a");
                    fprintf(fich,"PointLight{\n");
					fwprintf(fich,L"ambientIntensity %s\n",vIDC_IA0);
					fwprintf(fich,L"attenuation %s %s %s\n",vIDC_A0,vIDC_A1,vIDC_A2);
					fwprintf(fich,L"color %s %s %s\n",vIDC_C0,vIDC_C1,vIDC_C2);
					fwprintf(fich,L"intensity %s\n", vIDC_I0);
					fwprintf(fich,L"location %s %s %s\n",vIDC_L0,vIDC_L1,vIDC_L2);
					fwprintf(fich,L"radius %s\n", vIDC_R0);
	


					fprintf(fich,"}\n");
					
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;
					EndDialog(hwnd, 1);
					return 0;
			
				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;


				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}
/***************************************************/
LRESULT CALLBACK Fond(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Ang0[10]=TEXT("0"),vIDC_Ang1[10]=TEXT("0"),vIDC_Ang2[10]=TEXT("0"),vIDC_C1[10]=TEXT("1"),vIDC_C2[10]=TEXT("0"),vIDC_C3[10]=TEXT("0"),
		  vIDC_C4[10]=TEXT("0"),vIDC_C5[10]=TEXT("1.0"),vIDC_C6[10]=TEXT("2.0"),vIDC_C7[10]=TEXT("0"),vIDC_C8[10]=TEXT("0"),vIDC_C9[10]=TEXT("0"),vIDC_C10[10]=TEXT("1"),vIDC_C11[10]=TEXT("0"),vIDC_C12[10]=TEXT("0"),
		  vIDC_Ang3[10]=TEXT("0"),vIDC_Ang4[10]=TEXT("1.0"),vIDC_Ang5[10]=TEXT("2.0"),vIDC_G1[10]=TEXT("1"),vIDC_G2[10]=TEXT("0"),vIDC_G3[10]=TEXT("0"),
		  vIDC_G4[10]=TEXT("0"),vIDC_G5[10]=TEXT("1.0"),vIDC_G6[10]=TEXT("2.0"),vIDC_G7[10]=TEXT("0"),vIDC_G8[10]=TEXT("0"),vIDC_G9[10]=TEXT("0"),vIDC_G10[10]=TEXT("1"),vIDC_G11[10]=TEXT("0"),vIDC_G12[10]=TEXT("0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Angle1,vIDC_Ang0 );
			SetDlgItemText( hwnd, IDC_Angle2,vIDC_Ang1 );
			SetDlgItemText( hwnd, IDC_Angle3,vIDC_Ang2 );
			SetDlgItemText( hwnd, IDC_C1,vIDC_C1);
			SetDlgItemText( hwnd, IDC_C2,vIDC_C2);
			SetDlgItemText( hwnd, IDC_C3,vIDC_C3);
			SetDlgItemText( hwnd, IDC_C4,vIDC_C4);
			SetDlgItemText( hwnd, IDC_C5,vIDC_C5);
			SetDlgItemText( hwnd, IDC_C6,vIDC_C6);
			SetDlgItemText( hwnd, IDC_C7,vIDC_C7 );
			SetDlgItemText( hwnd, IDC_C8,vIDC_C8 );
			SetDlgItemText( hwnd, IDC_C9,vIDC_C9 );
			SetDlgItemText( hwnd, IDC_C10,vIDC_C10);
			SetDlgItemText( hwnd, IDC_C11,vIDC_C11);
			SetDlgItemText( hwnd, IDC_C12,vIDC_C12);
			SetDlgItemText( hwnd, IDC_Angle4,vIDC_Ang3);
			SetDlgItemText( hwnd, IDC_Angle5,vIDC_Ang4);
			SetDlgItemText( hwnd, IDC_Angle6,vIDC_Ang5);
			SetDlgItemText( hwnd, IDC_G1,vIDC_G1 );
			SetDlgItemText( hwnd, IDC_G2,vIDC_G2 );
			SetDlgItemText( hwnd, IDC_G3,vIDC_G3 );
			SetDlgItemText( hwnd, IDC_G4,vIDC_G4);
			SetDlgItemText( hwnd, IDC_G5,vIDC_G5);
			SetDlgItemText( hwnd, IDC_G6,vIDC_G6);
			SetDlgItemText( hwnd, IDC_G7,vIDC_G7);
			SetDlgItemText( hwnd, IDC_G8,vIDC_G8);
			SetDlgItemText( hwnd, IDC_G9,vIDC_G9);
			SetDlgItemText( hwnd, IDC_G10,vIDC_G10);
			SetDlgItemText( hwnd, IDC_G11,vIDC_G11);
			SetDlgItemText( hwnd, IDC_G12,vIDC_G12 );
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckDlgButton(hwnd, IDC_BAS, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_HAUT, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_COTE, BST_CHECKED);
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Angle1,vIDC_Ang0,10);
					GetDlgItemText(hwnd,IDC_Angle2,vIDC_Ang1,10);
					GetDlgItemText(hwnd,IDC_Angle3,vIDC_Ang2,10);
					GetDlgItemText(hwnd,IDC_C1,vIDC_C1,10);
					GetDlgItemText(hwnd,IDC_C2,vIDC_C2,10);
					GetDlgItemText(hwnd,IDC_C3,vIDC_C3,10);
					GetDlgItemText(hwnd,IDC_C4,vIDC_C4,10);
					GetDlgItemText(hwnd,IDC_C5,vIDC_C5,10);
					GetDlgItemText(hwnd,IDC_C6,vIDC_C6,10);
					GetDlgItemText(hwnd,IDC_C7,vIDC_C7,10);
					GetDlgItemText(hwnd,IDC_C8,vIDC_C8,10);
					GetDlgItemText(hwnd,IDC_C9,vIDC_C9,10);
					GetDlgItemText(hwnd,IDC_C10,vIDC_C10,10);
					GetDlgItemText(hwnd,IDC_C11,vIDC_C11,10);
					GetDlgItemText(hwnd,IDC_C12,vIDC_C12,10);
					GetDlgItemText(hwnd,IDC_Angle4,vIDC_Ang3,10);
					GetDlgItemText(hwnd,IDC_Angle5,vIDC_Ang4,10);
					GetDlgItemText(hwnd,IDC_Angle6,vIDC_Ang5,10);
					GetDlgItemText(hwnd,IDC_G1,vIDC_G1,10);
					GetDlgItemText(hwnd,IDC_G2,vIDC_G2,10);
					GetDlgItemText(hwnd,IDC_G3,vIDC_G3,10);
					GetDlgItemText(hwnd,IDC_G4,vIDC_G4,10);
					GetDlgItemText(hwnd,IDC_G5,vIDC_G5,10);
					GetDlgItemText(hwnd,IDC_G6,vIDC_G6,10);
					GetDlgItemText(hwnd,IDC_G7,vIDC_G7,10);
					GetDlgItemText(hwnd,IDC_G8,vIDC_G8,10);
					GetDlgItemText(hwnd,IDC_G9,vIDC_G9,10);
					GetDlgItemText(hwnd,IDC_G10,vIDC_G10,10);
					GetDlgItemText(hwnd,IDC_G11,vIDC_G11,10);
					GetDlgItemText(hwnd,IDC_G12,vIDC_G12,10);

					
					++nb_objet;
                   	fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"Background{\n");
					fwprintf(fich,L"skyAngle [%s %s %s]\n",vIDC_Ang0, vIDC_Ang1, vIDC_Ang2);
					fwprintf(fich,L"skyColor [%s %s %s %s %s %s %s %s %s %s %s %s]\n",vIDC_C1, vIDC_C2, vIDC_C3, vIDC_C4, vIDC_C5, vIDC_C6, vIDC_C7, vIDC_C8, vIDC_C9, vIDC_C10, vIDC_C11, vIDC_C12);
					fwprintf(fich,L"groundAngle [%s %s %s]\n",vIDC_Ang3, vIDC_Ang4, vIDC_Ang5);
					fwprintf(fich,L"groundColor [%s %s %s %s %s %s %s %s %s %s %s %s]\n",vIDC_G1, vIDC_G2, vIDC_G3, vIDC_G4, vIDC_G5, vIDC_G6, vIDC_G7, vIDC_G8, vIDC_G9, vIDC_G10, vIDC_G11, vIDC_G12);
					
					fprintf(fich,"}\n");
					
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;
			        EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;
				
				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}
/**************************************************/
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     
     HMENU      hMenu ;
     char nom[20]="objet";
	 static int i,controle,controle2,saisie,axes,background;
	
	 PAINTSTRUCT  ps ;
	 HDC hdc;
	 
     switch (message)
     {
	 case WM_COMMAND:
          hMenu = GetMenu (hwnd) ;
          
          switch (LOWORD (wParam))
          {
         

          case ID_EDITION_QUIT :
			   fopen_s(&fich,"toto.wrl","a");
			  fprintf(fich,"] }\n");
			 fopen_s(&S,"toto1.wrl" , "r");
			
				 
			 

			   while ((fgets(chaine, 100, S)) != NULL) 
			fputs(chaine,fich);
			

			  fclose(S);
			 
			 remove("toto1.wrl");
			

			 fprintf(fich,"\n Inline{\n");
			 fprintf(fich,"url \"axes.wrl\" }\n");
			
			   SendMessage (hwnd, WM_CLOSE, 0, 0) ;

			   fclose(fich);

			   return 0;
			   
			    
			  
          case ID_EDITION_NEW :
			   fopen_s(&S, "toto1.wrl", "w");
			  fclose(S);
			   fopen_s(&fich,"toto.wrl","w");
			   fprintf(fich,"#VRML V2.0 utf8 \n");
			   fprintf(fich,"Group { \n");
			   fprintf(fich,"children [\n");
			   fprintf(fich,"#début animation\n");
			   fclose(fich);

			   EnableMenuItem(hMenu, ID_EDITION_NEW, MF_GRAYED);
			   EnableMenuItem(hMenu, ID_GEOMETRY_CYLINDRE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRY_SPHERE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRY_BOX, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRY_CONE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRY_TEXTE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_DIRECTIONNELLE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_PONCTUELLE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_SPOT, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_SENSOR_CY, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_SENSOR_PL, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_SENSOR_SP, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_FOND_FOND, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_EDITION_QUIT, MF_ENABLED);
			   InvalidateRect (hwnd, NULL, TRUE) ;
               return 0;

          
		  
          case ID_GEOMETRY_CYLINDRE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_CYLINDRE), hwnd, (DLGPROC)cylindre);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		 case ID_GEOMETRY_SPHERE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_SPHERE), hwnd, (DLGPROC)sphere);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		 case ID_GEOMETRY_BOX: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_Box), hwnd, (DLGPROC)Box);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRY_CONE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_CONE), hwnd, (DLGPROC)CONE);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_GEOMETRY_TEXTE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_Texte), hwnd, (DLGPROC)Texte);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
		  
			case ID_LUMIERE_DIRECTIONNELLE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_LUMIERE_DIRECTIONNELLE), hwnd, (DLGPROC)LUMIERE_DIRECTIONNELLE);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_LUMIERE_PONCTUELLE: 
			  
				DialogBox(NULL,MAKEINTRESOURCE(IDD_LUMIERE_SPOT), hwnd, (DLGPROC)LUMIERE_SPOT);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_LUMIERE_SPOT:
				DialogBox(NULL,MAKEINTRESOURCE(IDD_LUMIERE_PONCTUELLE), hwnd, (DLGPROC)LUMIERE_PONCTUELLE);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;


			case ID_SENSOR_CY: 
			  
				DialogBox(NULL,MAKEINTRESOURCE(IDD_cylindreSensor), hwnd, (DLGPROC)cylSensor);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			 case ID_SENSOR_PL: 
			  
				DialogBox(NULL,MAKEINTRESOURCE(IDD_planSensor), hwnd, (DLGPROC)planSensor);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
			   case ID_SENSOR_SP: 
			  
				DialogBox(NULL,MAKEINTRESOURCE(IDD_SphereSensor), hwnd, (DLGPROC)SphereSensor);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;



			case ID_FOND_FOND: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_Fond), hwnd, (DLGPROC)Fond);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;


			/*case ID_AIDE: 
			  
              DialogBox(NULL,MAKEINTRESOURCE(IDD_AIDE), hwnd, (DLGPROC)aide);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;*/
			   
		  }
               
		  case WM_PAINT:
          
          hdc = BeginPaint (hwnd, &ps) ;
		  
          EndPaint (hwnd, &ps) ;
		 
          
		 
          return 0 ;
		  case WM_CLOSE:
	           	DestroyWindow(hwnd);
		
			case WM_DESTROY:
			  PostQuitMessage(0);
			return 0;
     }
         
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}

