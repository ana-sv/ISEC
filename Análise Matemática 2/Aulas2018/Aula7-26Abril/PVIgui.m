function varargout = PVIgui(varargin)
% PVIGUI MATLAB code for PVIgui.fig
%      PVIGUI, by itself, creates a new PVIGUI or raises the existing
%      singleton*.
%
%      H = PVIGUI returns the handle to a new PVIGUI or the handle to
%      the existing singleton*.
%
%      PVIGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PVIGUI.M with the given input arguments.
%
%      PVIGUI('Property','Value',...) creates a new PVIGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before PVIgui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to PVIgui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help PVIgui

% Last Modified by GUIDE v2.5 26-Apr-2018 16:14:57

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @PVIgui_OpeningFcn, ...
                   'gui_OutputFcn',  @PVIgui_OutputFcn, ...
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


% --- Executes just before PVIgui is made visible.
function PVIgui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to PVIgui (see VARARGIN)

% Choose default command line output for PVIgui
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes PVIgui wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = PVIgui_OutputFcn(hObject, eventdata, handles) 
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

strF = get(handles.eF,'String') %% faz trabalhar o que tem a tag eF
f = @(t,y) eval(vectorize(strF));

a  = str2num(get(handles.eA,'String'));
b  = str2num(get(handles.eB,'String'));
n  = str2num(get(handles.eN,'String'));
y0 = str2num(get(handles.eY0,'String'));

%%Exata é igual para todos 
sExata = dsolve(['Dy=', strF],...
                ['y(',num2str(a),')=',num2str(y0)]);
t = a:(b-a)/n:b;
yExata = eval(char(sExata));



switch  1  %%controla que metodo está ativado
    case get(handles.rbEuler,'Value')
        yEuler = N_euler(f,a,b,n,y0);
        erroEuler = abs(yExata - yEuler);
        tabela = [t.', yEuler.', yExata.', erroEuler.'];
        %disp(tabela)- atualizar para lancar no objeto tabela da GUI
        plot(t,yEuler,'-r')
        hold on
        plot(t,yExata, 'b')
        hold off
        grid on
        legend('Euler','Exacta')      
        
        
    case get(handles.rbEulerMelhorado,'Value')
        warndlg('Não está implementada', 'AVISO', 'modal')
    case get(handles.rbRK2,'Value')
        warndlg('Não está implementada', 'AVISO', 'modal')
    case get(handles.rbRK4,'Value')
        warndlg('Não está implementada', 'AVISO', 'modal')
    case get(handles.rbODE45,'Value')
        warndlg('Não está implementada', 'AVISO', 'modal')
    case get(handles.rbTodos,'Value') 
end 
        
        







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



function ey0_Callback(hObject, eventdata, handles)
% hObject    handle to ey0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of ey0 as text
%        str2double(get(hObject,'String')) returns contents of ey0 as a double


% --- Executes during object creation, after setting all properties.
function ey0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to ey0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
