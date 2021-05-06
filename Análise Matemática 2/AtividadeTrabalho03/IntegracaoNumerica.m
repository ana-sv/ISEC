function varargout = IntegracaoNumerica(varargin)
% INTEGRACAONUMERICA MATLAB code for IntegracaoNumerica.fig
%      INTEGRACAONUMERICA, by itself, creates a new INTEGRACAONUMERICA or raises the existing
%      singleton*.
%
%      H = INTEGRACAONUMERICA returns the handle to a new INTEGRACAONUMERICA or the handle to
%      the existing singleton*.
%
%      INTEGRACAONUMERICA('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in INTEGRACAONUMERICA.M with the given input arguments.
%
%      INTEGRACAONUMERICA('Property','Value',...) creates a new INTEGRACAONUMERICA or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before IntegracaoNumerica_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to IntegracaoNumerica_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help IntegracaoNumerica

% Last Modified by GUIDE v2.5 10-May-2017 18:44:36

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @IntegracaoNumerica_OpeningFcn, ...
                   'gui_OutputFcn',  @IntegracaoNumerica_OutputFcn, ...
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


% --- Executes just before IntegracaoNumerica is made visible.
function IntegracaoNumerica_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to IntegracaoNumerica (see VARARGIN)

% Choose default command line output for IntegracaoNumerica
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes IntegracaoNumerica wait for user response (see UIRESUME)
% uiwait(handles.figureIntegracaoNumerica);






MyAtualizar(handles);


% --- Outputs from this function are returned to the command line.
function varargout = IntegracaoNumerica_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in cbGrelha.
function cbGrelha_Callback(hObject, eventdata, handles)
% hObject    handle to cbGrelha (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbGrelha
if (get(hObject,'Value'))
    grid on
else
    grid off
end

% --- Executes on button press in pbAtualiza.
function pbAtualiza_Callback(hObject, eventdata, handles)
% hObject    handle to pbAtualiza (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
MyAtualizar(handles);

% --- Função auxiliar associada ao botão Atualizar.
function MyAtualizar(handles)
% handles estrutura de dados com as handles para os objetos...

testeNumReala=MException('MATLAB:Act:badnum','Introduza um número real em "a".');
testeNumRealb=MException('MATLAB:Act:badnum','Introduza um número real em "b".');
testeBMenor=MException('MATLAB:Act:badnum','Introduza um número superior a "a".');
testeN=MException('MATLAB:Actual:badnum','"n" inválido. Introduza um numero inteiro positivo.');
testeNPar=MException('MATLAB:Actual:badnum','Para utilizar este método o "n" tem que ser par.');

try
    syms x;
    strF=get(handles. tFuncao,'String');
    f=@(x) eval(vectorize(char(strF)));
    a=str2num(get(handles.eA,'String'));
    n=str2num(get(handles.eN,'String'));
    b=str2num(get(handles.eB,'String'));

    % - Validação dos parâmetros de entrada
    if (~(isnumeric(a) && isreal(a) && ~isempty(a)))
        set(handles.eA, 'BackgroundColor', 'r')
        throw(testeNumReala)
    else
        set(handles.eA, 'BackgroundColor', [1 1 1])
    end

    if (~(isnumeric(b) && isreal(b) && ~isempty(b)))
        set(handles.eB, 'BackgroundColor', 'r')
        throw(testeNumRealb)
    else
        set(handles.eB, 'BackgroundColor', [1 1 1])
    end

    if (b<=a)
        set(handles.eB, 'BackgroundColor', 'r')
        throw(testeBMenor)
    else
        set(handles.eB, 'BackgroundColor', [1 1 1])
    end

    if (~(isnumeric(n) && ~isempty(n) && n>0 && n==floor(n)))
        set(handles.eN, 'BackgroundColor', 'r')
        throw(testeN)
    else
        set(handles.eN, 'BackgroundColor', [1 1 1])
    end


    % - Verificar o botão que está seleccionado
    escolhe = find([handles.rbRT ...
        handles.rbRS...
        handles.rTodos] == get(handles.bgFormulasINumerica,'SelectedObject'));

    TRAPEZIOS = 1;
    SIMPSON = 2;
    TODOS = 3;
    
    % - Cálculo da primitiva pela função quad
    q=integral(f,a,b);
    format short
    set(handles.resQuad,'String',q);
    
    % - Discretização do domínio
    x=a:(b-a)/n:b;
    y=f(x);
    
    % - Cálculo da Regra dos Trapézios e de Simpson
    rT=RTrapezios(f,a,b,n);
    rT=sum(rT);
    erroTrapezios=abs(q-rT);
    rS=RSimpson(f,a,b,n);
    rS=sum(rS);
    erroSimpson=abs(q-rS);
    axes(handles.axes1)
    
    % - Plots e tabelas conforme a escolha do utilizador
    switch(escolhe)
        case TRAPEZIOS
            plot(x,y,'-b*', 'LineWidth',2);
            hold on
            legend('Função')
            xx=[x,x(end),x(1)];
            yy=[y,0,0];
            fill(xx,yy,[0.2 0.5 0.5]);
            set(handles.uitabela,'ColumnName',[{'Solucão Exata'},{'Valor Aproximado'},{'Erro'}]);
            set(handles.uitabela,'Data',num2cell([q,rT,erroTrapezios]));
        case SIMPSON
            if(mod(n,2))
                set(handles.eN, 'BackgroundColor', 'r')
                throw(testeNPar)
            else
                set(handles.eN, 'BackgroundColor', [1 1 1])
            end
            plot(x,y,'-b*','LineWidth',2);
            hold on
            legend('Função')
            xx=[x,x(end),x(1)];
            yy=[y,0,0];
            fill(xx,yy,[0.2 0.5 0.5]);
            set(handles.uitabela,'ColumnName',[{'Solucão Exata'},{'Valor Aproximado'},{'Erro'}]);
            set(handles.uitabela,'Data',num2cell([q,rS,erroSimpson]));
        case TODOS
            plot(x,y,'-b*','LineWidth',2);
            hold on
            legend('Função')
            xx=[x,x(end),x(1)];
            yy=[y,0,0];
            fill(xx,yy,[0.2 0.5 0.5]);
            set(handles.uitabela,'ColumnName',[{'Solucão Exata'},{'Regra Trapézios'},{'Erro Trapézios'},{'Regra Simpson'},{'Erro Simpson'}]);
            set(handles.uitabela,'Data',num2cell([q,rT,erroTrapezios,rS,erroSimpson]));
    end

    hold off;

catch Me
    errordlg(['Ocorreu um Erro: ' Me.message],'Erro','modal');
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

% --- Executes when user attempts to close figureIntegracaoNumerica.
function figureIntegracaoNumerica_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figureDerivacaoNumerica (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
%delete(hObject);
set(hObject,'Visible','Off');


% --- Executes on button press in cbMPontos.
function cbMPontos_Callback(hObject, eventdata, handles)
% hObject    handle to cbMPontos (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbMPontos
if (get(hObject,'Value'))
    [x_coord y_coord] = ginput(1);
    text(x_coord,y_coord,['(', num2str(x_coord),',', num2str(y_coord),')'])
else
    
end


% --------------------------------------------------------------------
function ficheiro_Callback(hObject, eventdata, handles)
% hObject    handle to ficheiro (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function autores_Callback(hObject, eventdata, handles)
% hObject    handle to autores (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Autor();

% --------------------------------------------------------------------
function relatorio_Callback(hObject, eventdata, handles)
% hObject    handle to relatorio (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
winopen('relatorio_atividade3_final.pdf');


% --------------------------------------------------------------------
function sair_Callback(hObject, eventdata, handles)
% hObject    handle to sair (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
figureIntegracaoNumerica_CloseRequestFcn(handles.figureIntegracaoNumerica);



function resQuad_Callback(hObject, eventdata, handles)
% hObject    handle to resQuad (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of resQuad as text
%        str2double(get(hObject,'String')) returns contents of resQuad as a double

% --- Executes during object creation, after setting all properties.
function resQuad_CreateFcn(hObject, eventdata, handles)
% hObject    handle to resQuad (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
