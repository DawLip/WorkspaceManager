# Instalacja 
```
make
```
W ./src/config.h ustaw ścieżkę do programu
``` cpp
struct Config {
    string program_path = "/home/david/workspace/studies/WorkspaceManager/"; // <= ustaw swoją ścieżkę
    bool debug = true;
};
```
Następnie dodaj ten katalog do **$PATH**\
**Uruchomienie programu i stworzenie pierwszego workspace**
```
wm new your_workspace_name your_workspace_short_name
```

# Komendy programu
**wm new [name]** -> tworzy nowy workspace w bierzącym folderze o nazwie [name]\
**wm update [ws_name] [ws_property] [value]** -> edytuje workspace [ws_name].[ws_property] na wartość [value]\
**wm [name]** -> uruchamia skrypt inicializujący dla workspace [name]

# Inicjalizacja workspace
Każdy workspace przy stworzeniu tworzy plik init.ws.bash.\
Można w nim ustawić inicjalizacjęworkspace.\
Można wpisać dowolne polecenia powłoki, będą one wysyłane do odpowiednich okien tmuxa.
## Komendy preprocesora
#> window [nazwa] - tworzy nowe okno tmux o nazwie [nazwa]\
#> pane [nazwa] - kolejne komendy będą wysyłane do pane [nazwa]\
#> split h - dzieli pane horyzontalnie\
#> split v - dzieli pane wertykalnie

## Przykład kodu preprocesora:
```bash
#> window main-server
#> pane 0
echo 'Starting main server...'
#> split h
#> pane 1
echo 'Waiting for errors'
#> window web-frontend
echo 'Starting web frontend...'
```