function varargout = GUI_MNEDO(varargin)
% GUI_MNEDO M-file for GUI_MNEDO.fig
%      GUI_MNEDO, by itself, creates a new GUI_MNEDO or raises the existing
%      singleton*.
%
%      H = GUI_MNEDO returns the handle to a new GUI_MNEDO or the handle to
%      the existing singleton*.
%
%      GUI_MNEDO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI_MNEDO.M with the given input arguments.
%
%      GUI_MNEDO('Property','Value',...) creates a new GUI_MNEDO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI_MNEDO_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI_MNEDO_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI_MNEDO

% Last Modified by GUIDE v2.5 27-Oct-2016 17:24:04

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_MNEDO_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_MNEDO_OutputFcn, ...
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


% --- Executes just before GUI_MNEDO is made visible.
function GUI_MNEDO_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI_MNEDO (see VARARGIN)

% Choose default command line output for GUI_MNEDO
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
Atualizar(handles);

% UIWAIT makes GUI_MNEDO wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI_MNEDO_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pbAtualizar.
function pbAtualizar_Callback(hObject, eventdata, handles)
% hObject    handle to pbAtualizar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Atualizar(handles);


function eF_Callback(hObject, eventdata, handles)
% hObject    handle to eF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eF as text
%        str2double(get(hObject,'String')) returns contents of eF as a double


% --- Executes during object creation, after setting all properties.
function eF_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eA_Callback(hObject, eventdata, handles)
% hObject    handle to eA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eA as text
%        str2double(get(hObject,'String')) returns contents of eA as a double


% --- Executes during object creation, after setting all properties.
function eA_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eB_Callback(hObject, eventdata, handles)
% hObject    handle to eB (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eB as text
%        str2double(get(hObject,'String')) returns contents of eB as a double


% --- Executes during object creation, after setting all properties.
function eB_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eB (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eN_Callback(hObject, eventdata, handles)
% hObject    handle to eN (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eN as text
%        str2double(get(hObject,'String')) returns contents of eN as a double


% --- Executes during object creation, after setting all properties.
function eN_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eN (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eY0_Callback(hObject, eventdata, handles)
% hObject    handle to eY0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eY0 as text
%        str2double(get(hObject,'String')) returns contents of eY0 as a double


% --- Executes during object creation, after setting all properties.
function eY0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eY0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function Atualizar(handles)
strF=get(handles.eF,'String');
f   =@(t,y) eval(vectorize(strF));
a   = str2num(get(handles.eA,'String'));
b   = str2num(get(handles.eB,'String'));
n   = str2num(get(handles.eN,'String'));
y0  = str2num(get(handles.eY0,'String'));

escolhabg=get(handles.bgMetodos,'SelectedObject');
escolha=find([handles.rbEuler,...
              handles.rbEulerM,...
              handles.rbRK2,...
              handles.rbRK4,...
              handles.rbODE45,...
              handles.rbTodos]==escolhabg);
 EULER=1;
 EULERM=2;
 RK2=3;
 RK4=4;
 MODE45=5;
 TODOS=6;
 
yEuler=N_Euler_v2(f,a,b,n,y0);
yRK2=N_RK2(f,a,b,n,y0);
yRK4=NRK4(f,a,b,n,y0);
sExata=dsolve(['Dy=',strF],...
      ['y(',num2str(a),')=',num2str(y0)]);
t=a:(b-a)/n:b;
yExata=eval(vectorize(char(sExata)));
erroEuler=abs(yExata-yEuler);
erroRK2=abs(yExata-yRK2);
erroRK4=abs(yExata-yRK4);

plot(t,yExata);
hold on

switch escolha
    case EULER
        plot(t,yEuler,'r');
        legend('yExata','yEuler');
        tabela=[t.',yExata.',yEuler.',erroEuler.'];
        set(handles.uiTabela,'Data',num2cell(tabela));
        set(handles.uiTabela,'ColumnName',{'t','Exata','Euler','ErroEuler'});
     case EULERM
         warndlg('Método não implementado');
     case RK2
        plot(t,yRK2,'g');
        legend('yExata','yRK2');
        tabela=[t.',yExata.',yRK2.',erroRK2.'];
        set(handles.uiTabela,'Data',num2cell(tabela));
        set(handles.uiTabela,'ColumnName',{'t','Exata','RK2','ErroRK2'});
     case RK4
        plot(t,yRK4,'y');
        legend('yExata','yRK4');
        tabela=[t.',yExata.',yRK4.',erroRK4.'];
        set(handles.uiTabela,'Data',num2cell(tabela));
        set(handles.uiTabela,'ColumnName',{'t','Exata','RK4','ErroRK4'});
      case MODE45
         warndlg('Método não implementado');
     case TODOS
        plot(t,yEuler,'r');
        plot(t,yRK2,'g');
        plot(t,yRK4,'k');
        legend('yExata','yEuler','yRK2','yRK4');      
        tabela=[t.',yExata.',yEuler.',yRK2.',yRK4.',...
                erroEuler.',erroRK2.',erroRK4.'];      
        set(handles.uiTabela,'Data',num2cell(tabela));
        set(handles.uiTabela,'ColumnName',{'t','Exata','Euler','RK2',...
                                           'RK4','ErroEuler','ErroRK2',...
                                           'ErroRK4'});
end      
hold off;
grid on;
