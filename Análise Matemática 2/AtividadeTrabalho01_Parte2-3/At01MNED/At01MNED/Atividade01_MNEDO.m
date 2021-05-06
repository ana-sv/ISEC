function varargout = Atividade01_MNEDO(varargin)
% ATIVIDADE01_MNEDO M-file for Atividade01_MNEDO.fig
%      ATIVIDADE01_MNEDO, by itself, creates a new ATIVIDADE01_MNEDO or raises the existing
%      singleton*.
%
%      H = ATIVIDADE01_MNEDO returns the handle to a new ATIVIDADE01_MNEDO or the handle to
%      the existing singleton*.
%
%      ATIVIDADE01_MNEDO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in ATIVIDADE01_MNEDO.M with the given input arguments.
%
%      ATIVIDADE01_MNEDO('Property','Value',...) creates a new ATIVIDADE01_MNEDO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Atividade01_MNEDO_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Atividade01_MNEDO_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Atividade01_MNEDO

% Last Modified by GUIDE v2.5 27-Apr-2020 19:38:29
% Arm�nio Correia .: armenioc@isec.pt

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Atividade01_MNEDO_OpeningFcn, ...
                   'gui_OutputFcn',  @Atividade01_MNEDO_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Atividade01_MNEDO is made visible.
function Atividade01_MNEDO_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Atividade01_MNEDO (see VARARGIN)

% Choose default command line output for Atividade01_MNEDO
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
I=imread('logo.PNG','PNG');
imshow(I,[],'Parent',handles.axLogo)

% UIWAIT makes Atividade01_MNEDO wait for user response (see UIRESUME)
% uiwait(handles.figurePrincipal);


% --- Outputs from this function are returned to the command line.
function varargout = Atividade01_MNEDO_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pb_IntfTexto.
function pb_IntfTexto_Callback(hObject, eventdata, handles)
% hObject    handle to pb_IntfTexto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
InterfaceTexto_PVI;


% --- Executes on button press in pb_GUI.
function pb_GUI_Callback(hObject, eventdata, handles)
% hObject    handle to pb_GUI (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
MaquinaEDO1();


% --------------------------------------------------------------------
function MAutor_Callback(hObject, eventdata, handles)
% hObject    handle to MAutor (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Autor();


% --------------------------------------------------------------------
function MRelatorio_Callback(hObject, eventdata, handles)
% hObject    handle to MRelatorio (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

%eval(['!' pwd '\Relatorio_Atividade02.pdf'])%Abre o PDF que cont�m o relat�rio da actividade
winopen('Relatorio.pdf')


% --------------------------------------------------------------------
function MDE_Callback(hObject, eventdata, handles)
% hObject    handle to MDE (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
web('http://www.mathworks.com/products/matlab/examples.html?file=/products/demos/shipping/matlab/odedemo.html', '-browser')


% --------------------------------------------------------------------
function MSair_Callback(hObject, eventdata, handles)
% hObject    handle to MSair (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
SN = questdlg('Quer sair?','SAIR','Sim','N�o','Sim');
if strcmp(SN,'N�o')
    return 
end
delete(handles.figurePrincipal);


% --- Executes when user attempts to close figurePrincipal.
function figurePrincipal_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figurePrincipal (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
% SN = questdlg('Quer sair?', 'Sair','Sim','N�o','Sim');
% if strcmp(SN,'N�o')
%     return 
% end;
% delete(hObject);
MSair_Callback([],[],handles);


% --------------------------------------------------------------------
function MFile_Callback(hObject, eventdata, handles)
% hObject    handle to MFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pbRelatorio.
function pbRelatorio_Callback(hObject, eventdata, handles)
% hObject    handle to pbRelatorio (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
winopen('Relatorio.pdf')


% --------------------------------------------------------------------
function Moodle_Callback(hObject, eventdata, handles)
% hObject    handle to Moodle (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
web('https://moodle.isec.pt/moodle/mod/forum/view.php?id=125240', '-browser')
